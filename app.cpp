#include <bits/stdc++.h>
using namespace std;
string S, T, ret;
// stack<char> stk;
int main()
{
	cin >> S >> T;
	for (char a : S)
	{
		ret += a; // stk.push(a);
		if (ret.size() >= T.size() && ret.substr(ret.size() - T.size(), T.size()) == T)
		// if(stk.size()>=T.size()&&stk.top()==T[T.size()-1])
		//{
		//  string ss =""; ss+= stk.top(); stk.pop();
		// }
		// reverse(ss.begin(),ss.end());
		// if(T!=ss)
		//{
		// for(int i : ss){ stk.push(i)};
		//}
		{
			ret.erase(ret.end() - T.size(), ret.end());
		}
	}
	// if(stk.size()==0){cout <<"FRULA"} else{ while(stk.size()) ret+=stk.top(); stk.pop();} reverse(ret.begin(); ret.end()); cout << ret<<"\n";
	if (!ret.size())
		cout << "FRULA"
			 << "\n";
	else
		cout << ret << "\n";
	return 0;
}