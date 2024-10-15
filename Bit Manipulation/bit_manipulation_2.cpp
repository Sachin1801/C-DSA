// bit_manipulation_2.cpp
#include<iostream>
using namespace std;

int get_ith_bit(int n)
{
	int i;
	cin>>i;
	n= n>>i;
	return n&1;
}

int set_ith_bit(int n, int i)
{
	int mask = 1;
	
	mask = mask<<i;
	n = n|mask;
	return n;
}

int clear_ith_bit(int n, int i)
{
	
	int mask  = ~(1<<i);
	n = n&mask;
	return n;
}

void clear_last_i_bits(int &n, int i)
{
	int mask = -1;
	mask = mask<<i;
	n = n&mask;
	return ;
}

int clear_bits_in_range(int n, int i, int j)
{
	int a= (~0)<<(j+1);
	int b = (1<<i) - 1;
	int mask = a|b;
	n = n&mask;
	return n;
}

int main(){

	int n;
	cin>>n;
	// int i;
	// cin>>i;

	// int ans1,ans2,ans3;

	// ans1 = get_ith_bit(n,i);	

	// ans2= set_ith_bit(n,i);

	// ans3 = clear_ith_bit(n,i);

	// clear_last_i_bits(n,i);
	// cout<<n<<endl;

	cout<<clear_bits_in_range(n,2,3);

	// cout<<ans1<<endl;

	// cout<<ans2<<endl;

	// cout<<ans3<<endl;

	return 0;
}