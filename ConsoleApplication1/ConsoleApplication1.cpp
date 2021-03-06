#include "stdafx.h"
#include <stdio.h>

#include "dhdc.h"
#include "drdc.h"


#define K   1000.0



// simple spring model which pulls the device
// towards the center of the workspace;
// if the user lifts the device 5cm above the center,
// the application exits
int
compute_my_forces(double px, double py, double pz,
	double *fx, double *fy, double *fz)
{
	// spring model
	*fx = -K * px;
	*fy = -K * py;
	*fz = -K * pz;

	// exit condition
	if (pz > 0.05) return 1;
	else          
	return 0;
}

/*

int main(int  argc,	char **argv)
{
	int    done = 0;
	double px, py, pz;
	double fx, fy, fz;
	double oa, ob, og;
	double f[DHD_MAX_DOF];
	double p[DHD_MAX_DOF];
	double rot[3][3];

	double nullPose[DHD_MAX_DOF] = { 0.0, 0.0, 0.0,  // base  (translations)
		0.0, 0.0, 0.0,  // wrist (rotations)
		0.0};          // gripper
	if (dhdOpen() < 0) {
		printf("error: cannot open device\n");
	}

	// open the first available device
	if (drdOpen() < 0) {
		printf("error: cannot open device (%s)\n", dhdErrorGetLastStr());
		dhdSleep(2.0);
		return -1;
	}

	// print out device identifier
	if (!drdIsSupported()) {
		printf("unsupported device\n");
		printf("exiting...\n");
		dhdSleep(2.0);
		drdClose();
		return -1;
	}
	printf("%s haptic device detected\n\n", dhdGetSystemName());

	// perform auto-initialization
	if (!drdIsInitialized() && drdAutoInit() < 0) {
		printf("error: auto-initialization failed (%s)\n", dhdErrorGetLastStr());
		dhdSleep(2.0);
		return -1;
	}
	else if (drdStart() < 0) {
		printf("error: regulation thread failed to start (%s)\n", dhdErrorGetLastStr());
		dhdSleep(2.0);
		return -1;
	}
/*
	// move to center
	//drdMoveTo(nullPose); - for this to work auto initialize should happen using the 
	//robotic sdk 
	dhdEmulateButton(1); //To emulate button behavior on the sigma.7 
	
	printf("spring model applied...\n");


	while (!done) {

		// get end-effector position
		dhdGetPositionAndOrientationDeg(&px, &py, &pz, &oa, &ob, &og);
		//drdGetPositionAndOrientation(p,0); //Trying to use the drd version
		// compute force model
		//drdSleep(2.0);
		done = compute_my_forces(px, py, pz, &fx, &fy, &fz);
		//for (int i = 0; i < 10000000; i++);
		printf("Position: %lf %lf %lf %lf %lf %lf \n", px, py, pz, oa, ob, og);
		dhdSleep(2.0);
		// apply forces
		//dhdSetForce(fx, fy, fz);
		
		// exit if the button is pushed
		done += dhdGetButton(0);
		printf("%d\n" , dhdErrorGetLast());
	}

	printf("exiting application\n");
	//drdStop();
	//drdClose();
	//dhdClose();
	return 0;
}
*/