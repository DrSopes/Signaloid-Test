#include <stdio.h>
#include <math.h>
#include <uxhw.h>

/*
 *	Pressure drop in a fluid flowing through a cylindrical tube of constant cross section
 *
 *	Overview:
 *	Models an equation for a fluid pressure model from Poiseuille.
 *
 *	Inputs:
 *	The inputs and their ranges are:
 *	-	`L`:	    0.5 to 1.5
 *	-	`mu`:		1 normal distribution with deviation of 0.1
 *	-	`Q`:		5 normal distribution with deviation of 0.2
 *	-	`rad`:		0.09 to 0.11
 *
 *	Outputs:
 *	The output is the pressure difference between the edges of the pipe, `deltaP`
 */


double calculatePressureDrop(double mu, double L, double Q, double rad) {
    return (8 * mu * L * Q) / (M_PI * pow(rad, 4)); // Poiseuille equation on radius basement
}

int
main(int argc, char *  argv[]) {
    
	// Define the parameters with uncertainties using Signaloid functions
    double L = UxHwDoubleUniformDist(0.5, 1.5);  // Length of the tube (arbitrary units)
    double mu = UxHwDoubleGaussDist(1, 0.1); // Dynamic viscosity (arbitrary units)
    double Q = UxHwDoubleGaussDist(5, 0.2);  // Volumetric flow rate (arbitrary units)
    double rad = UxHwDoubleUniformDist(0.09, 0.11);  // Radius of the tube (arbitrary units)

    double deltaP = calculatePressureDrop(mu, L, Q, rad);    // Calculate the pressure drop

    printf("Calculated Pressure Drop: %lf\n", deltaP);    // Print the result

    return 0;
}
