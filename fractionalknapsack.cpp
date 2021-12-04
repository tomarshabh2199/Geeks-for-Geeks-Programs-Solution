#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};
 // } Driver Code Ends

bool compare(struct Item a,struct Item b){
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
}
double fractionalKnapsack(int w, struct Item arr[],int n){
    sort(arr,arr+n,compare);
    int currentweight=0;
    double finalvalue=0.0;
    for(int i=0;i<n;i++)
    {
        if(currentweight+arr[i].weight<=w){
           currentweight+=arr[i].weight;
           finalvalue+=arr[i].value;
    }
    else
    {
        int remain=w-currentweight;
        finalvalue+=arr[i].value*((double)remain/arr[i].weight);
           break;
    }
}
    return finalvalue;
    }

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends