#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

/**
* Gives the dimension of the specified vector
* @param v a vector in dimension-coordinates format
* @return the dimension of this vector
*/
int dim(const double v[])
{
	return v[0];
}

/**
* Gives a string representation of this vector in the form
* <x1, x2, ..., xn>, where x1 is the second element of the array,
* x2, the second element of the array, etc and n is the dimension
* of the vector and the first element of the array.
* @param v a dimension-coordinates array representation of a
* vector.
* @return a string representation of the specified vector
*/
string vtos(const double v[])
{
	stringstream sout;
	sout<<"<"<<v[1];
	for (int i=2;i<=v[0];i++)
		sout<<", "<<v[i];
	sout<<">";
	return sout.str();
}

/**
* Determines whether two vectors are equal; two vectors are
* equal if they have the same dimension and their
* corresponding coordinates are equal.
* @param v1 a vector
* @param v2 a vector
* @return true if the specified vectors are equal;
* otherwise, false
*/
bool equal(const double v1[], const double v2[])
{
	for(int i=0;i<=v1[0];i++)
		{
		if(v1[i]!=v2[i])
			return false;
		}
	return true;
}
/**
* Computes the sum of the specified vectors
* @param v1 a vector
* @param v2 a vector
* @return the sum of the specified vectors if they have the same
* dimension or NULL, otherwise
*/
double* add(const double v1[], const double v2[])
{
	if(v1[0]!=v2[0])
		return NULL;
	double *w = new double [static_cast<int>(v1[0]+1)];
	w[0]=v1[0];
	for(int i=1;i<=v1[0];i++)
		w[i]=v1[i]+v2[i];
	return w;
}

/**
* Computes the difference of the specified vectors
* @param v1 a vector
* @param v2 a vector
* @return the v1-v2 if the vectors have the same
* dimension or NULL, otherwise
*/
double* sub(const double v1[], const double v2[])
{
	if(v1[0]!=v2[0])
		return NULL;
	double *result = new double [static_cast<int>(v1[0]+1)];
	result[0]=v1[0];
	for(int i=1;i<=v1[0];i++)
		result[i]=v1[i]-v2[i];
	return result;
}

/**
* Computes the length of this vector
* @param v a dimension-coordinates representation of a vector
* @return the length of the specified vector
*/
double length(const double v[])
{
	double sum=0;
	for(int i=1;i<=v[0];i++)
		sum+=pow(v[i],2);
	return sqrt(sum);
}
/**
* Computes the dot product of two vectors
* @param v1 a vector
* @param v2 a vector
* @return the dot product of v1 and v2 if they have the same
* dimension; otherwise, NAN
*/
double dot(const double v1[], const double v2[])
{
	int prod=0;
	if(v1[0]!=v2[0])
		return NAN;
	for(int i=1;i<=v1[0];i++)
		prod+=v1[i]*v2[i];
	return prod;
}

/**
* Computes the product of a vector and a number (scalar)
* @param v a vector
* @param n a number
* @return a vector whose coordinates are those of v, each
* multiplied by n; that is, <nv1, nv2, nv3,...,nvn>
*/
double* mult(const double v[], double n)
{
	double *w = new double [static_cast<int>(v[0]+1)];
	w[0]=v[0];
	for(int i=1;i<=v[0];i++)
		w[i]=v[i]*n;
	return w;
}

int main() {
	int size;
	cout<<"Enter the dimension of three vectors -> ";
	cin>>size;
	double*vect1=new double[size+1];
	double*vect2=new double[size+1];
	double*vect3=new double[size+1];
	vect1[0]=size;
	vect2[0]=size;
	vect3[0]=size;
	cout<<"Enter the coordinates of v1 -> ";
	for(int i=1;i<=size;i++)
		cin>>vect1[i];
	cout<<"Enter the coordinates of v2 -> ";
	for(int i=1;i<=size;i++)
			cin>>vect2[i];
	cout<<"Enter the coordinates of v3 -> ";
	for(int i=1;i<=size;i++)
			cin>>vect3[i];
	cout<<"\nv1 = "<<vtos(vect1)<<endl;
	cout<<"v2 = "<<vtos(vect2)<<endl;
	cout<<"v3 = "<<vtos(vect3)<<endl;
	cout<<"\nv1 +v2 = "<<vtos(add(vect1,vect2))<<endl;
	cout<<"(v2 + v3) * v1 = "<<dot(add(vect2,vect3),vect1)<<endl;
	cout<<"|v2 - v3| = "<<length(sub(vect2,vect3))<<endl;
	cout<<"v1*v2 = "<<dot(vect1,vect2)<<" and |v2||v1| = "<<length(vect2)*length(vect1)<<endl;
	delete [] vect1;
	delete [] vect2;
	delete [] vect3;
	cout<<"\nEnter the dimension of three additional vectors -> ";
	cin>>size;
	double*vect4=new double[size+1];
	double*vect5=new double[size+1];
	double*vect6=new double[size+1];
	vect4[0]=size;
	vect5[0]=size;
	vect6[0]=size;
	cout<<"Enter the coordinates of v4 -> ";
	for(int i=1;i<=size;i++)
		cin>>vect4[i];
	cout<<"Enter the coordinates of v5 -> ";
	for(int i=1;i<=size;i++)
			cin>>vect5[i];
	cout<<"Enter the coordinates of v6 -> ";
	for(int i=1;i<=size;i++)
			cin>>vect6[i];
	cout<<"\nv4 = "<<vtos(vect4)<<endl;
	cout<<"v5 = "<<vtos(vect5)<<endl;
	cout<<"v6 = "<<vtos(vect6)<<endl;
	cout<<"\nv4*(v5 + v6) = v4*v5 + v4*v6 \n(v4+v5)/|v4+v5| = "<<vtos(mult(add(vect4,vect5),1/length(add(vect4,vect5))))<<endl;
	cout<<"v5/|v5+v6| + v6/|v5+v6| = "<<vtos(add(mult(vect5,1/length(add(vect5,vect6))),mult(vect6,1/length(add(vect5,vect6)))))<<endl;
	cout<<"(v4+v5)/|v4+v5| ";
	if(equal(mult(add(vect4,vect5),1/length(add(vect4,vect5))),add(mult(vect5,1/length(add(vect5,vect6))),mult(vect6,1/length(add(vect5,vect6)))))==true)
		cout<<"= ";
	else
		cout<<"<> ";
	cout<<"v5/|v5+v6| + v6/|v5+v6|"<<endl;
	return 0;
}
