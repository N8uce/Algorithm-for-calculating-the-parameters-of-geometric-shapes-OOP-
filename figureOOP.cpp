#include <iostream> 
#define _USE_MATH_DEFINES 
#include <math.h> 
#include <string> 
using namespace std; 
class Figure 
{ 
public: 
virtual string calculate() = 0; 
}; 
class twoD : public Figure 
{ 
protected: 
double S = 0; 
double P = 0; 
}; 
class circle : public twoD 
{ 
double R; 
public: 
circle() 
{ 
cout << "Введите длину радиуса круга" << endl; 
cin >> R; 
} 
circle(double R1) 
{ 
R = R1; 
} 
string calculate() 
{ 
S = M_PI * (R * R); 
P = 2 * M_PI * fabs(R); 
return "Площадь = " + to_string(S) + "\nПериметр = " + 
to_string(P); 
} 
}; 
class ellipse :public twoD 
{ 
double a,b; 
public: 
ellipse() 
{ 
cout << "Введите длину большой и малой полуоси эллипса" << 
endl; 
} 
cin >> a >> b; 
ellipse(double a1, double b1) 
{ 
a = a1; 
b = b1; 
} 
string calculate() 
{ 
S = M_PI * fabs(a * b); 
P = (4 * (M_PI * fabs(a) * fabs(b) + (fabs(a) - fabs(b))  
* (fabs(a) - fabs(b)))) / (fabs(a) + fabs(b)); 
return "Площадь = " + to_string(S) + "\nПериметр = " + 
to_string(P); 
} 
}; 
class square : public twoD 
{ 
double a; 
public: 
square(double a1) 
{ 
a = a1; 
} 
{ 
string calculate() 
S = a*a; 
P = S; 
return "Площадь = " + to_string(S) + "\nПериметр = " + 
to_string(P); 
} 
}; 
class pentagon : public twoD 
{ 
double a; 
public: 
pentagon(double a1) 
{ 
a = a1; 
} 
{ 
string calculate() 
S = ((a*a)/4)*sqrt(25+10*sqrt(5)); 
P= 5*fabs(a); 
return "Площадь = " + to_string(S) + "\nПериметр = " + 
to_string(P); 
} 
}; 
class rectangle :public twoD 
{ 
double a, b; 
public: 
rectangle() 
{ 
cout << "Введите длину большой и малой стороны 
прямоугольника" << endl; 
cin >> a >> b; 
} 
rectangle(double a1, double b1) 
{ 
a = a1; 
b = b1; 
} 
string calculate() 
{ 
S = fabs(a * b); 
P = 2 * (fabs(a) + fabs(b)); 
return "Площадь = " + to_string(S) + "\nПериметр = " + 
to_string(P); 
} 
}; 
class threeD:public Figure 
{ 
protected: 
double V = 0; 
double H = 0; 
double Sa = 0; 
}; 
 
class tetrahedron4 : public threeD 
{ 
double a, b; 
public: 
    tetrahedron4() 
    { 
        cout << "Введите длину стороны основания, бокового ребра, 
высоты тетраэдра" << endl; 
        cin >> a >> b >> H; 
    } 
    string calculate() 
    { 
        if (H != 0) 
        { 
            Sa = a * a + 2 * fabs(a) * sqrt(b * b - (a * a / 4)); 
            V = (Sa * fabs(H)) / 3; 
            return "Площадь = " + to_string(Sa) + "\nОбъём = " + 
to_string(V); 
        } 
        square B(a); 
        return B.calculate(); 
    } 
}; 
 
class cone : public threeD 
{ 
double R; 
public: 
    cone() 
    { 
      cout<<"Введите длину радиуса и высоты конуса"<<endl; 
      cin>>R>>H; 
    } 
    string calculate() 
    { 
        if (H != 0) 
        { 
            Sa = (M_PI*fabs(R)) *(fabs(R) + sqrt(R*R + H*H)); 
            V = (M_PI * R*R*fabs(H))/3; 
            return "Площадь = " + to_string(Sa) + "\nОбъём = " + 
to_string(V); 
        } 
        circle B(R); 
        return B.calculate(); 
    } 
}; 
class cube : public threeD 
{ 
double a; 
public: 
cube() 
{ 
cout<<"Введите длину грани куба"<<endl; 
cin>>a; 
}  
string calculate() 
{ 
Sa = 6*a*a; 
V = fabs(a)*a*a; 
return "Площадь = " + to_string(Sa) + "\nОбъём = " + 
to_string(V); 
} 
}; 
class prism : public threeD 
{ 
double a; 
public: 
prism() 
{ 
cout<<"Введите длину стороны основания, высоты 
призмы"<<endl; 
cin>>a>>H; 
} 
string calculate() 
{ 
if(H !=0) 
{ 
Sa = 5*fabs(a)*(sqrt(pow(fabs(a)/(2*sin(M_PI/5)),2)
(a*a)/4)+fabs(H)); 
V = ((5*fabs(a*a*H))/4)*sqrt((1/(sin(M_PI/5)*sin(M_PI/5)))-1); 
return "Площадь = " + to_string(Sa) + "\nОбъём = " + 
to_string(V); 
} 
pentagon P(a); 
return P.calculate(); 
} 
}; 
class cylinder : public threeD 
{ 
10 
double R; 
public: 
cylinder() 
{ 
cout<<"Введите длину радиуса и высоты цилиндра"<<endl; 
cin>>R>>H; 
} 
string calculate() 
{ 
if(H !=0) 
{ 
Sa = 2*M_PI*fabs(R*H); 
V = M_PI*fabs(R*R*H); 
return "Площадь = " + to_string(Sa) + "\nОбъём = " + 
to_string(V); 
} 
circle C(R); 
return C.calculate(); 
} 
}; 
class ellipsoid : public threeD 
{ 
double a,b; 
public: 
ellipsoid() 
{ 
cout<<"Введите длину трёх полуосей эллипсоида"<<endl; 
cin>>a>>b>>H; 
} 
string calculate() 
{ 
const double P = 1.6075; 
double temp=fabs(H); 
if(a==0) 
{ 
H=a; 
a=temp; 
} 
if(b==0) 
{ 
H=b; 
b=temp; 
} 
if(H !=0) 
{ 
Sa = 4*M_PI 
*pow(((pow(fabs(a),P)*pow(fabs(b),P)+pow(fabs(b),P)*pow(fabs(H),P)
 +pow(fabs(a),P)*pow(fabs(H),P))/3),1/P); 
V = (4*M_PI *fabs(a*b*H))/3; 
return "Площадь = " + to_string(Sa) + "\nОбъём = " + 
to_string(V); 
} 
ellipse E(a,b); 
return E.calculate(); 
} 
}; 
int main() 
{ 
Figure *A =new circle(); 
cout<<A->calculate(); 
Figure *B =new ellipsoid(); 
cout<<B->calculate(); 
return 0; 
}
