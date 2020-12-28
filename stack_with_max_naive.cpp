#include<bits/stdc++.h>
using namespace std;

class StackWithMax {
    vector<int> stack;

  public:

    void Push(int value) {
        stack.push_back(value);
    }

    void Pop() {
        assert(stack.size());
        stack.pop_back();
    }

    int Max() const {
        assert(stack.size());
        return *max_element(stack.begin(), stack.end());
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;
    int currentmin,currentmax,sz;
    string query;
    string value;

    //StackWithMax stack;
    stack<int>st;
    vector<pair<int,int>>temp;

    for (int i = 0; i < num_queries; ++i)
    {
        cin >> query;
        if (query == "push")
        {
            cin >> value;

            st.push(stoi(value));
            if(temp.size() == 0)
            {
              temp.push_back(make_pair(stoi(value), stoi(value)));
            }
            else
            {
              currentmin = temp[temp.size()-1].first;
              currentmax = temp[temp.size()-1].second;
              currentmin = min(currentmin, stoi(value));
              currentmax = max(currentmax, stoi(value));
              temp.push_back(make_pair(currentmin,currentmax));
            }
        }
        else if (query == "pop")
        {
            st.pop();
            temp.pop_back();
        }
        else if (query == "max") {
            //cout << stack.Max() << "\n";
            if(temp.size() == 0)
            {
              cout<<"-1"<<endl;
            }
            else
              cout<<temp[temp.size()-1].second<<endl;
        }
        else {
            assert(0);
        }
    }
    return 0;
}
