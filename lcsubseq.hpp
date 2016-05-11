int lcs(string a, string b) {
int dp[1024][1024];
for (int i=0; i<a.length(); i++)
fill(dp[i], dp[i]+b.length(), 0);

dp[0][0] = (a[0]==b[0]); //for Java, use a.charAt() and b.charAt()

//initial conditions (first column and row are filled in)
for (int i=1; i<a.length(); i++)
dp[i][0] = max(dp[i-1][0], (int)(a[i]==b[0]));

for (int j=1; j<b.length(); j++)
dp[0][j] = max(dp[0][j-1], (int)(a[0]==b[j]));

for (int i=1; i<a.length(); i++) //actual algorithm
for (int j=1; j<b.length(); j++)
if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1]+1;
else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

return dp[a.length()-1][b.length()-1]; //the answer is stored here
}
