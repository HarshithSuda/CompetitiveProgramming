#include<bits/stdc++.h>
using namespace std;

void solve(int N){
    int c=0;
    for(int fghij=1234;fghij<=98765/N;fghij++){
        int abcde=fghij*N; //computing one of the many 
        //mathematical possibilities
        int temp,user=(fghij<10000); //temp->storing abcde and
        //fghij
        //user-->stores the occurence of numbers -> 0-9
        //user=(fghij<10000)-->check if f==0
        temp=abcde;
        while(temp){    
            user|=(1<<(temp%10)); //storing last bit of temp in user
            temp/=10;
        }
        temp=fghij;
        while(temp){
            user|=(1<<(temp%10));
            temp/=10;
        }
        if(user==(1<<10)-1){ //checking if all bits 0-9 are set
            c++;
            printf("%05d / %05d = %d\n",abcde,fghij,N);
        }
    }
    if(c==0){
        printf("There are no solutions for %d.\n",N);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n=0,count=0; //for eof values
    while(scanf("%d", &n), n){
        count++;
        if(count>1){
            printf("\n");
        }
        solve(n);
    }

    return 0;
}