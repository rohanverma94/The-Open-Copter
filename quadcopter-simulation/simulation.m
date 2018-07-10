    % Simulation times, in seconds.
    start_time = 0;
    end_time = 10;
    dt = 0.005;
    times = start_time:dt:end_time;
     
    % Number of points in the simulation.
    N = numel(times);
     
    % Initial simulation state.
    x = [0; 0; 10];
    xdot = zeros(3, 1);
    theta = zeros(3, 1);
     
    % Simulate some disturbance in the angular velocity.
    % The magnitude of the deviation is in radians / second.
    deviation = 100;
    thetadot = deg2rad(2 * deviation * rand(3, 1) - deviation);
     
    % Step through the simulation, updating the state.
    for t = times
    	% Take input from our controller.
    	i = input(t);
    	omega = thetadot2omega(thetadot, theta);
     
    	% Compute linear and angular accelerations.
    	a = acceleration(i, theta, xdot, m, g, k, kd);
     	omegadot = angular_acceleration(i, omega, I, L, b, k);
    	omega = omega + dt * omegadot;
    	thetadot = omega2thetadot(omega, theta);
    	theta = theta + dt * thetadot;
    	xdot = xdot + dt * a;
    	x = x + dt * xdot;
    end
     
    % Compute thrust given current inputs and thrust coefficient.
    function T = thrust(inputs, k)
    	% Inputs are values for wi^2
    	T = [0; 0; k * sum(inputs)];
    end
     
    % Compute torques, given current inputs, length, drag coefficient, and thrust coefficient.
    function tau = torques(inputs, L, b, k)
    	% Inputs are values for wi
    	tau = [L * k * (inputs(1) - inputs(3); L * k * (inputs(2) - inputs(4); b * (inputs(1) - inputs(2) + inputs(3) - inputs(4))];
    end
    function a = acceleration(inputs, angles, xdot, m, g, k, kd)
    	gravity = [0; 0; -g];
    	R = rotation(angles);
    	T = R * thrust(inputs, k);
    	Fd = -kd * xdot;
    	a = gravity + 1 / m * T + Fd;
    end
     
    function omegadot = angular_acceleration(inputs, omega, I, L, b, k)
    	tau = torques(inputs, L, b, k);
    	omegaddot = inv(I) * (tau - cross(omega, I * omega));
    end