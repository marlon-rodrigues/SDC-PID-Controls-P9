# SDC-Controls-PID-P9

## Controls PID
[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)

In this project, I revisited the lake race track from the Behavioral Cloning Project. This time, however, I implemented a PID controller in C++ to maneuver the vehicle around the track.

The simulator provided me the cross track error (CTE) and the velocity (mph) I needed to compute the appropriate steering angle.

## Overview 

PID controllers are simple reactive controllers that are widely used. The difference between the measured and the desired value (setpoint) of a process variable of a system is fed into the PID controller as an error signal. Depending on the PID parameters a control output is generated to steer the system closer to the setpoint. In the project, a car simulator produces the error signal as the distance between the actual car position on the road and a reference trajectory, known as cross-track error (CTE). The PID controller is designed to minimize the distance to this reference trajectory. The primary control output of the PID controller here is the steering angle.

### P - Proportional Gain

The proportional term computes an output proportional to the cross-track error. A pure P - controller is untable and at best oscillates about the setpoint. The proportional gain contribuites to a control output to the steering angle of the form ["-K_p cte"] with a positive ["K_p"].

### D - Differential Gain

The oscillations caused by purely D control can be mitigated by a term proportional to the derivative of the cross-track error. The derivative gain contributes a control output of the form ["-K_d d/dt cte"], with a positive constant ["K_d"].

### I - Integral Gain

A third contribution is given by the integral gain which simply sums up the cross-track error over time. The corresponding contribution to the steering angle is given by ["-K_i sim(cte)"]. Thereby, biases can be mitigated, for instance if a zero steering angle does not correspond to a straight trajectory. At high speed, this term can also be useful to accumulate a large error signal quickly, for instance, when the car is carried out sideways from the reference trajectory. This allows to reduce proportional gain, which causes oscillations at high speeds. It is also benefitial to limit the memory of this term to avoid overshooting. As we can see in the hyperparameters tunning section, this component had no effect in this project, as it's value was set to 0.

## Hyperparameters Tunning

I decided to manually tune the hyperparameters described above. I started using the values used in the lessons, ["K_p = 0.2, K_i = 0.004 and K_d = 30"]. Although the car showed an overhal decent behavior, at some parts of the track it showed a sinusoidal behavior. I then decided to used a value of 0 for the integral gain and noticed that no difference existed between the updated K_i and the old value. I then increased the throttle value to 0.5. That caused the car to run off the road in several spots, which made me drop the values of both K_p and K_d. That helped the car present a better behavior, but still not perfect, as it ran off the road in the 2nd turn after the bridge. I then reduced the value of the throttle to 0.4 and the car behaved much better, presenting a consistent drive across the track. To complete, I decided to use the follwoing values for my hyperparameters: ["K_p = 1, K_i = 0.0, K_d = 20, Throttle = 0.4"]. 

## Video with Results

A video of the results can be found [here](https://youtu.be/dQHF_KRFk10).