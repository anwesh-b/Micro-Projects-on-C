/*WAP for subneting calculator
Author:Anwesh Budhathoki
Date:2019/02/02
About: This program takes the ip address and its CIDR value and give the information of the network*/


#include<stdio.h>
#include<conio.h>
#include<stdlib.h
#include<math.h>
int main()
{
	int ip0,ip1,ip2,ip3,cidr,rem,NoOfNetwork,ValidHost,BlockSize,i=0;
	printf("Enter IP Address:\n");
	a:
	{
	scanf("%d.%d.%d.%d",&ip0,&ip1,&ip2,&ip3);
	printf("Enter its CIDR value.:\n");
	scanf("%d",&cidr);
	}
	if((ip0>224)||(ip1>255)||(ip2>255)||(ip3>255)||(cidr>32))
	{
		printf("Syntax error");
		getch();
		system("cls");
		printf("Please enter valid ip and CIDR\n");
		goto a;
	}
	rem=cidr%8;
	ValidHost;
	if((cidr==24)||(cidr==16)||(cidr==8))
	BlockSize=1;
	else
	BlockSize=pow(2,8-rem);
	if(cidr>=24)
	{
		NoOfNetwork=pow(2,rem);
		ValidHost=(pow(2,8-rem)-2);
	}
	else if(cidr>=16)
	{
		NoOfNetwork=pow(2,8+rem);
		ValidHost=(pow(2,16-rem)-2);
	}
	else if(cidr>=8)
	{
		NoOfNetwork=pow(2,16+rem);
		ValidHost=(pow(2,24-rem)-2);
	}
	if(cidr>=24)
	printf("\n1) Subnet mask: 255.255.255.%d",(256-BlockSize));
	else if(cidr>=16)
	printf("\n1) Subnet mask: 255.255.%d.0",(256-BlockSize));
	else if(cidr>=8)
	printf("\n1) Subnet mask: 255.%d.0.0",(256-BlockSize));
	printf("\n2) No of network: %d",NoOfNetwork);
	printf("\n3) Valid Host: %d",ValidHost);
	printf("\n4) Block Size: %d",BlockSize);
	while(i<ip3)
	{
		i+=BlockSize;
	}
	i-=BlockSize;
	if(ip0>=192)
	{
		printf("\n\nNetwork ID\t= %d.%d.%d.%d",ip0,ip1,ip2,i);
		printf("\nFirst IP\t= %d.%d.%d.%d",ip0,ip1,ip2,i+1);
		printf("\nLast IP\t\t= %d.%d.%d.%d",ip0,ip1,ip2,(i+BlockSize-2));
		printf("\nBroadcast IP\t= %d.%d.%d.%d",ip0,ip1,ip2,(i+BlockSize-1));
	}
	if((ip0>=128)&&(ip0<192))
	{
		if(cidr>=24)
		{	
			printf("\n\nNetwork ID\t= %d.%d.%d.%d",ip0,ip1,ip2,i);
			printf("\nFirst IP\t= %d.%d.%d.%d",ip0,ip1,ip2,i+1);
			printf("\nLast IP\t\t= %d.%d.%d.%d",ip0,ip1,ip2,(i+BlockSize-2));
			printf("\nBroadcast IP\t= %d.%d.%d.%d",ip0,ip1,ip2,(i+BlockSize-1));
		}
		if((cidr>=16)&&(cidr<24))
		{
			printf("\n\nNetwork ID\t= %d.%d.%d.0",ip0,ip1,i);
			printf("\nFirst IP\t= %d.%d.%d.1",ip0,ip1,i);
			printf("\nLast IP\t\t= %d.%d.%d.254",ip0,ip1,(i+BlockSize-1));
			printf("\nBroadcast IP\t= %d.%d.%d.255",ip0,ip1,(i+BlockSize-1));
		}
	}
	if(ip0<128)
	{
		if(cidr>=24)
		{	
			printf("\n\nNetwork ID\t= %d.%d.%d.%d",ip0,ip1,ip2,i);
			printf("\nFirst IP\t= %d.%d.%d.%d",ip0,ip1,ip2,i+1);
			printf("\nLast IP\t\t= %d.%d.%d.%d",ip0,ip1,ip2,(i+BlockSize-2));
			printf("\nBroadcast IP\t= %d.%d.%d.%d",ip0,ip1,ip2,(i+BlockSize-1));
		}
		if((cidr>=16)&&(cidr<24))
		{
			printf("\n\nNetwork ID\t= %d.%d.%d.0",ip0,ip1,i);
			printf("\nFirst IP\t= %d.%d.%d.1",ip0,ip1,i);
			printf("\nLast IP\t\t= %d.%d.%d.254",ip0,ip1,(i+BlockSize-1));
			printf("\nBroadcast IP\t= %d.%d.%d.255",ip0,ip1,(i+BlockSize-1));
		}
		if(cidr<16)
		{
			printf("\n\nNetwork ID\t= %d.%d.0.0",ip0,i);
			printf("\nFirst IP\t= %d.%d.0.1",ip0,i);
			printf("\nLast IP\t\t= %d.%d.255.254",ip0,(i+BlockSize-1));
			printf("\nBroadcast IP\t= %d.%d.255.255",ip0,(i+BlockSize-1));
		}
	}
	getch();
}
