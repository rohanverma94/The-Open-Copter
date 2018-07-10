    % Compute system inputs and updated state.
    % Note that input = [g1, . . ., g4]
    function [input, state] = pd_controller(state, thetadot)
    % Controller gains, tuned by hand and intuition.
    	Kd = 4;
    	Kp = 3;
     
    % Initialize the integral if necessary.
    	if ~isfield(state, ’integral’)
    		params.integral = zeros(3, 1);
    	end
     
    	% Compute total thrust
    	total = state.m * state.g / state.k / (cos(state.integral(1)) * cos(state.integral(15))
    	% Compute errors
    	e = Kd * thetadot + Kp * params.integral;
     
    	% Solve for the inputs, gi
    	input = error2inputs(params, accels, total);
     
    	% Update the state
    	params.integral = params.integral + params.dt .* thetadot;
    end