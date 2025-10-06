#include<bits/stdc++.h>
using namespace std;

void solve(){
	int A,B,C;
	cin>>A>>B>>C;
	int x,y,z;
	for( x=-22;x<=22;x++){
		if(x*x<=C){
			for( y=-100;y<=100;y++){
				if(x!=y && x*x+y*y<=C){
					for( z=-100;z<=100;z++){
						if(z!=y && z!=x && x+y+z==A && x*y*z==B
							&& x*x+y*y+z*z==C){
							printf("%d %d %d\n",x,y,z);
							return;
						}
					}
				}
			}
		}
	}
	printf("No solution.\n");
	return;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}