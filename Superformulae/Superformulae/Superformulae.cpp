// Superformulae.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include "SDL.h"
#undef main //WHEN USING SDL THIS COMMAND IS NEEDED
#define USE_MATH_DEFINES
#define M_PI  3.14159265358979323846 //should be the value in the <math.h> directory
using namespace std;
double lerp(double axisValue) {
    int bounda = 0;
    int boundb = 359;
    return bounda + (axisValue * (boundb - bounda));
}
void superformula(double& x, double& y, double r, vector<double> p) {
    double m, n, na, nb, a, b;
    m = p[0];
    n = p[1];
    na = p[2];
    nb = p[3];
    a = p[4];
    b = p[5];
    double ra = pow(abs(cos((m * r) / 4) / a), na);
    double rb = pow(abs(sin((m * r) / 4) / b), nb);
    double raux = ra + rb;
    x = raux * cos(r);
    y = raux * sin(r);
}
int main()
{
    //equation of circle = x^2 + y^2 = c where x = rcos0 and y = rsin0
    //equation of ellipse = (x/a)^2 + (y/b) ^ 2 = 1 (a and b = semi-axis)
    //this is equal to r = ((cos0/a)^2 + ((sin0/b)^2)^-0.5
    //equation of superellipse (where exponents can be n and not just 2) = mod(x/a) ^ n + mod(x/b) ^ n = 1 or ((mod(cos0/a) ^ n + mod(sin0/b) ^ n)^-1/n
    //superformula = r = (mod(cos(m0/4)/a) ^ na + mod(sin(m0/4)/b) ^ nb) ^ -1/n
    //This formula can be used in polar coordinates to generate many complex shapes found in nature. The above equations are sourced from this link: https://www-users.york.ac.uk/~ss44/cyc/s/superformula.htm
    //To get the polar values at x and y for value of 0
    //x = r.cos(0)
    //y = r.sin(0)
    std::cout << "Hello World!\n";
    bool doubleInput = false;
    vector<double> doubleParameters;
    while (!doubleInput) 
    {
        doubleParameters.clear(); //in case the while loop failed and needs cleaning
        try {
            std::cout << "Please input the parameters you would like to use to generate your superformula in the form m n na nb a b";
            string parameters;
            getline(cin, parameters);
            istringstream spaceRemover(parameters);
            string doubleToAssign;
            while (getline(spaceRemover, doubleToAssign, ' ')) {
                doubleParameters.push_back(stod(doubleToAssign));
            }
            doubleInput = true; //finish while loop
        }
        catch (...) {
            cout << "Please input double values for this project" << std::endl;
            doubleInput = false;
        }
    }
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    int width = 1000;
    int height = 1000;
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Superformula experiment");
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderSetScale(renderer, 2, 2);
    double x, y;
    for (int i = 0; i <= 359; i++) {
        double rad = i * (M_PI / 180); //radians formula
        superformula(x, y, rad, doubleParameters); //these values will be between -1 through to 1 and will need to be interpolated on the sdl graph
        cout << "x: " << x << " y: " << y << endl;
        SDL_RenderDrawPointF(renderer, x, y);
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(10000);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
