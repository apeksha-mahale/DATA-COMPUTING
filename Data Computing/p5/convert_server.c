/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "convert.h"
#include<stdio.h>
#include<math.h>

int *
convert_hex_1_svc(int *argp, struct svc_req *rqstp)
{
	static int  result;
	char hex[10];
	char rev[10]="h";
	int i=0,j=0,len;
	int n=*argp;
	int rem;
	while(n>0) {
		rem=n%16;
		if(rem<=9) 
			hex[i++]=rem+48;
		else 
			hex[i++]=rem+55;
		n=n/16;
	}
	hex[i]='\0';
	len=i;
	i--;
	while(i>=0) {
		rev[j++]=hex[i--];
	}
	rev[len+1]='\0';
	result=(int)strtol(rev,NULL,16);
	/*
	 * insert server code here
	 */

	return &result;
}

int *
convert_oct_1_svc(int *argp, struct svc_req *rqstp)
{
	static int  result;
	int n,i,j,k,oct=0;
	n=*argp;
	i=1;
	while(n>0) {
		j=n%8;
		oct=oct+j*i;
		i=i*10;
		n=n/8;
	}
	result=oct;

	/*
	 * insert server code here
	 */

	return &result;
}
