#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
struct suffix{
	int index;
	int rank[2];
};
void radixSort(struct suffix suffixes[],int n,int index){
	int i;
	int pos[257];
	struct suffix *temp=new struct suffix[n];
	memset(pos,0,sizeof(pos));
	for(i=0;i<n;i++){
		pos[suffixes[i].rank[index]+1]++;
	}
	for(i=1;i<256;i++){
		pos[i]+=pos[i-1];
	}
	for(i=n-1;i>=0;i--){
		temp[pos[suffixes[i].rank[index]+1]-1]=suffixes[i];
		pos[suffixes[i].rank[index]+1]--;
	}
	for(i=0;i<n;i++){
		suffixes[i]=temp[i];
	}
	free(temp);
	if(index==0) return;
	else radixSort(suffixes,n,index-1);
}
int *buildSuffixArray(char *txt,int n){
	int i,k,rank,next_index,prev_rank;
	int *ind=new int[n];
	struct suffix *suffixes=new struct suffix[n];
	for(i=0;i<n;i++){
		suffixes[i].index=i;
		suffixes[i].rank[0]=txt[i];
		suffixes[i].rank[1]=(i+1<n)?txt[i+1]:-1;
	}
	radixSort(suffixes,n,1);
	for(k=4;k<2*n;k*=2){
		rank=0;
		prev_rank=suffixes[0].rank[0];
		suffixes[0].rank[0]=rank;
		ind[suffixes[0].index]=rank;
		for(i=1;i<n;i++){
			prev_rank=suffixes[i].rank[0];
			if(suffixes[i].rank[0]==prev_rank && suffixes[i].rank[1]==suffixes[i-1].rank[1]){
				suffixes[i].rank[0]=rank;
			}
			else{
				suffixes[i].rank[0]=rank+1;
				++rank;
			}
			ind[suffixes[i].index]=rank;
		}
		for(i=0;i<n;i++){
			next_index=suffixes[i].index + k/2;
			suffixes[i].rank[1]=(next_index<n)?ind[next_index]:-1;
		}
		radixSort(suffixes,n,1);
	}
	int *suffixArr=new int[n];
	for(i=0;i<n;i++){
		suffixArr[i]=suffixes[i].index;
	}
	free(ind);
	free(suffixes);
	return suffixArr;
} 
void printArr(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	char txt[]="ananan";
	int *suffixArr=buildSuffixArray(txt,strlen(txt));
	cout<<"Suffix Array is : ";
	printArr(suffixArr,strlen(txt));
	return 0;
}
