//Link: https://leetcode.com/problems/basic-calculator/ 
class Solution {
public:
    map<int, function<int(int a, int b)> > funmap;
    int cal(stack<char> &op, stack<int> &num ){
        int res = 0;
        cal_lab:
        if( op.size() == 0 || num.size() == 0 )
            return res;
        if( num.size() == 1 )
            return num.top();
        char opchar = op.top();
        if( opchar == ')' || opchar=='(')
            return res;
        if( opchar == 0 ){
            //cout<<"unfound operator "<<opchar<<endl;
            return res;
        }
        op.pop();
        int num2 = num.top();
        num.pop();
        int num1 = num.top();
        num.pop();
        if( num2 == 0 && opchar == '/')
            num2 = 1;
        res = funmap[opchar](num1, num2);
        cout<<"op "<<num1<<opchar<<num2<<endl;
        num.push(res);
        goto cal_lab;
    }
    int calculate(string s) {
        funmap['+'] = plus<int>();
        funmap['-'] = minus<int>();
        funmap['*'] = multiplies<int>();
        funmap['/'] = divides<int>();
        map<char, int> priority;
        priority['+'] = 1;
        priority['-'] = 1;
        priority['*'] = 2;
        priority['/'] = 2;
        stack<char> op;
        stack<int> num;
        bool hasNum = false;
        int n = 0;
        for( int i = 0; i<s.size(); i++){
            char c = s[i];
            if( c >= '0' && c<='9'){
                hasNum = true;
                n = n * 10 + (c-'0');
            }else{
                if( hasNum == true ){
                    num.push(n);
                    if( op.size()> 0 ){
                        char opchar= op.top();
                        if( priority[opchar] >= 2)
                            cal(op, num);
                    }
                    n = 0;
                }
                hasNum = false;
                if( c == ' '){
                    
                }else if( c== '('){
                    op.push(c);
                }else if( c==')'){
                    cal(op, num);
                    //cout<<") next"<<op.top()<<endl;
                    op.pop();
                }else{
                    if( op.size()>0 ){
                        char opchar= op.top();
                        if( priority[opchar] >= priority[c])
                            cal(op, num);
                    }
                    op.push(c);
                }
                /*else if( c== '+' || c== '-'){
                
                }else if(c=='*' || c == '/'){
                    
                }*/
            }
        }
        if( hasNum == true )
            num.push(n);
        cal(op, num);
        return num.top();
    }
};