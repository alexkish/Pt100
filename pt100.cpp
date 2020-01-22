#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{

	char R_c[10];
	sprintf(R_c,"%s",argv[1]);
	cout <<"R = "<< R_c <<" Ohm"<< endl;

	double R = atof(R_c);

	double par0 = 31.10753;
	double par1 = 2.225735;
	double par2 = 0.002443003;
	double par3 = -1.423662e-06;
	double par4 = -7.026191e-08;
	double par5 = 4.113309e-10;
	double par6 = -6.246151e-13;

	double T = par0 + par1*pow(R,1) + par2*pow(R,2) + par3*pow(R,3) + par4*pow(R,4) + par5*pow(R,5) + par6*pow(R,6);
	
	cout <<"Temperature = "<< T <<" K"<< endl;
	cout <<"            = "<< T-273.15 <<" C" << endl;
	
}