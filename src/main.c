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
 *	-	`L`:	0.15 to 0.25
 *	-	`mu`:		0.30 to 0.45
 *	-	`Q`:		1 10^-8 to 3 10^-8
 *	-	`rad`:		6 10^10 to 8 10^10
 *
 *	Outputs:
 *	The output is the pressure difference between the edges of the pipe, `Dp`
 */


double calculatePressureDrop(double mu, double L, double Q, double rad) {
    return (8 * mu * L * Q) / (M_PI * pow(rad, 4));
}

int
main(int argc, char *  argv[]) {
    
	// Define the parameters with uncertainties using Signaloid functions
    double mu = UxHwDoubleUniformDist(0.95, 1.05); // Dynamic viscosity (arbitrary units)
    double L = UxHwDoubleUniformDist(0.99, 1.01);  // Length of the tube (arbitrary units)
    double Q = UxHwDoubleUniformDist(0.98, 1.02);  // Volumetric flow rate (arbitrary units)
    double rad = UxHwDoubleUniformDist(0.99, 1.01);  // Radius of the tube (arbitrary units)

    // Calculate the pressure drop
    double deltaP = calculatePressureDrop(mu, L, Q, rad);

    // Print the result
    printf("Calculated Pressure Drop: %lf\n", deltaP);

    return 0;
}
