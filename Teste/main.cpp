#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> str = {"FACE", "ECAF", "ECAF", "ECAF"};
    stack<char> st;
    int brinde = 0;

    string v1, v2;

    v1 = str[0];
    for(int i = 0; i < str[0].size(); i++)
    {
        st.push(str[0][i]);
    }

    for(int i = 1; i < str.size(); i++)
    {
        for(int j = 0; j < str[i].size();j++)
        {
          v2[j] = st.top();
         cout <<   v2[j];   st.pop();
        }
        for(int j = 0; j < str[i].size();j++)
        {
            st.push(str[i][j]);
        }
        if(v2 == str[i])
        {
            brinde++;
            continue;
        }
        v1 = str[i];

    }

    cout << brinde << "\n";


    

}
