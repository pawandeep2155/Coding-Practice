#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define fi first
#define se second
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef double ld;
int n,r1,r2;
string s;
const int N=1e5+5;
int prime[N],dp[N];

void build_sieve()
{
    for(int i=0;i<N;i++) 
        prime[i]=1;
    prime[0]=0;
    prime[1]=0;
    for(int i=2;i<N;i++){
        if(prime[i]==1){
            for(int j=2*i;j<N;j+=i){
                if(prime[j]==1){
                    prime[j]=0;
                }
            }
        }
    }
    for(int i=1;i<N;i++){
        prime[i]=prime[i-1]+prime[i];
    }
}
int minPath(int index)
{
    if(index>n) 
        return 1e9;
    if(s[index-1]=='*') 
        return 1e9;
    if(index==n) 
        return 0;
    if(dp[index]!=-1) 
        return dp[index];
    int ans=1e9;
    ans=min(ans,1+minPath(index+1));
    ans=min(ans,1+minPath(index+2));

    if((prime[index]*r2)>=(index*r1)){
        ans=min(ans,1+minPath(index+prime[index]));
    }
    return dp[index]=ans;
}
int main()
{
    int T;
    cin>>T;
    build_sieve();

    while(T--)
    {
        cin>>r1>>r2>>n;
        cin>>s;
        memset(dp,-1,sizeof dp);
        int cnt=minPath(1);
        if(cnt>=1e9) cout<<"No way!"<<endl;
        else cout<<cnt<<endl; 
    }
}