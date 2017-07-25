#include "PID.h"

using namespace std;

/*
* Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	/* Where
	Kp = proportional
	Ki = integral
	Kd = differential
	cte = cross track error
	*/

	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;

	p_error = 0;
	d_error = 0;
	i_error = 0;

	prev_cte = 0;
	has_prev_cte = false;
}

void PID::UpdateError(double cte) {
	if(!has_prev_cte) {
		prev_cte = cte;
		has_prev_cte = true;
	}

	p_error = cte;
	i_error += cte;
	d_error = cte - prev_cte;

	prev_cte = cte;
}

double PID::TotalError() {
	return -Kp * p_error - Ki * i_error - Kd * d_error;
}

