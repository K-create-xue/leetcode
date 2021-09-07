class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2==1)
        return false;
//方法一：
        //每种情况的分析
        // std::stack<char> st;
        // for(int i=0;i<s.size();++i){
        // if(s[i]=='('||s[i]=='['||s[i]=='{'){
        //     st.push(s[i]);
        // }else{
        //     if(st.empty()) return false;
        //     if(s[i]==')' && st.top()!='(') return false;
        //     if(s[i]==']' && st.top()!='[') return false;
        //     if(s[i]=='}' && st.top()!='{') return false;
        //     st.pop();
        // }
        // }
        // if(st.empty())
        // return true;
        // return false;

//方法二：替换法，，总有(){}[]找出来，删了，直到找不到，如果还有值就false；
        //string::replace(pos,2,"");
        //pos位置必须是string内的下标，所以必需判断是否查找到
        //string::find(string);//找到返回下标，没找到返回string::npos(-1)
        int length=s.size();
        for(int i=0;i<length/2;++i){
            if(s.find("()")!=-1)
            s.replace(s.find("()"),2,"");
            else if(-1!=s.find("[]"))
            s.replace(s.find("[]"),2,"");
            else if(-1!=s.find("{}"))
            s.replace(s.find("{}"),2,"");
        }
        return s.size()==0;
        
//方法三：运气法，，代码我给了，对不对看你
       // return random()%100 < 50;
    }
};
