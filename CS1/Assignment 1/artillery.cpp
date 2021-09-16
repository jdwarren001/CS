/************************************************************************
*	This program calculates the trajectory of a missile when fired	*
*	with a certain initial velocity and firing angle.  The program	*
*	prints out the distance travelled horizontally and the time it	*
*	takes for the missile to hit the ground.			*
*	(This is not the way it would normally be calculated, but this	*
*	is just an exercise.)						*
*									*
*	Written by Sherine & a CSCI111 student Jackson Warren  	*
************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float	angle,			// initial tilt angle
		vinit,			// initial velocity
		vhoriz,			// horizontal velocity
		vvert,			// vertical velocity
		time,			// number of seconds since firing
		distance,		// horizontal distance travelled
		height;			// vertical distance
	const float g = 9.802;	// gravitational constant
	const float pi = 3.14159265;
	
//	input the initial angular velocity

	cout << "Enter the initial angular velocity: ";
	cin >> vinit;
	
//	loop for varying tilt angles */

	cout << "Enter the tilt angle in degrees (0 to finish): ";
	cin >> angle;
	while (angle > 0)
	{
		angle = angle * pi/180.;		// convert to radians
		time = 0;				// set up the clock
		height = 0;				// starting altitude
		vhoriz = vinit * cos(angle);		// initial horizontal velocity
		vvert = vinit * sin(angle);		// initial vertical velocity		

//		now step in units of 0.0001 seconds until the vertical distance is
//		less than or equal to zero - the projectile has hit the ground

		while (height >= 0)
		{
			time = time + 0.0001;
            height = (vvert * time) - (0.5 * -g * (time * time));
 		}
		distance = vhoriz * time;
 		cout << distance << " metres travelled in " << time << " seconds " <<  endl;

//		ask for the next angle

		cout << "\nEnter the tilt angle in degrees (0 to finish): ";
		cin >> angle;
	}
	return 0;
}
