#include<bits/stdc++.h>
using namespace std;

// struct Bracket {
//     Bracket(char type, int position):
//         type(type),
//         position(position)
//     {}
//
//     bool Matchc(char c) {
//         if (type == '[' && c == ']')
//             return true;
//         if (type == '{' && c == '}')
//             return true;
//         if (type == '(' && c == ')')
//             return true;
//         return false;
//     }
//
//     char type;
//     int position;
// };

int main() {
     std::string text;
     getline(std::cin, text);
    //
    // std::stack <Bracket> opening_brackets_stack;
    // for (int position = 0; position < text.length(); ++position) {
    //     char next = text[position];
    //
    //     if (next == '(' || next == '[' || next == '{') {
    //
    //         opening_brackets_stack.push()
    //     }
    //
    //     if (next == ')' || next == ']' || next == '}') {
    //         // Process closing bracket, write your code here
    //     }
    // }
stack<pair<int,char>>st;
int i,len=text.length(),res=-1;
for(i=0;i<len;i++)
{
  if((text[i] == '(') || (text[i] == '[') || (text[i]=='{'))
  {
    st.push(make_pair(i+1,text[i]));
  }
  else if((text[i] == ')') || (text[i] == '}') || (text[i] == ']'))
  {
    if(st.empty())
    {
      res = i+1;
      break;
    }
    else if((text[i] == ')') && (st.top().second != '('))
    {
      res=i+1;
      break;
    }
    else if((text[i] == ')') && (st.top().second == '('))
        st.pop();
    else if((text[i] == '}') && (st.top().second != '{'))
    {
      res=i+1;
      break;
    }
    else if((text[i] == '}') && (st.top().second == '{'))
        st.pop();
    else if((text[i] == ']') && (st.top().second != '['))
    {
      res = i+1;
      break;
    }
    else if((text[i] == ']') && (st.top().second == '['))
        st.pop();
  }
}
if(res!=-1)
{
  cout<<res;
}
else if(st.empty())
  cout<<"Success";
else if(res == -1)
{
  while(!st.empty())
  {
    res = st.top().first;
    st.pop();
    if(st.empty())
      break;
  }
  cout<<res;
}
    // Printing answer, write your code here

    return 0;
}
