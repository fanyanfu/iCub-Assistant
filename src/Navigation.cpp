#include "Navigation.h"

Navigation::Navigation()
{
	string path_model  = "../../dependencies/lpvDS-lib/models/coManip-DS-1/";
	string path_dim    = path_model +  "dimensions";
	string path_Priors = path_model +  "Priors";
	string path_Mu     = path_model +  "Mu";
	string path_Sigma  = path_model +  "Sigma";
	string path_A      = path_model +  "A_k";
	string path_att    = path_model +  "attractor";
	lpvDS planner (path_dim.c_str(), path_Priors.c_str(), path_Mu.c_str(), path_Sigma.c_str(), path_A.c_str());
	fileUtils fileUtils_;
	MatrixXd attractor = fileUtils_.readMatrix(path_att.c_str());
	VectorXd att = attractor.col(0); /* Fill in attractor */
}

Vector3d Navigation::linear_DS(VectorXd target)
{
	// this function takes target position described in robot's frame
	double max_v = 0.3;
	Vector3d x_dot = target.segment(0,3);
	Vector3d q_dot_obj = quat_log(target.segment(3,4)).segment(0,3);
	Vector3d q_dot_path = Vector3d(0,0,atan2(x_dot[1],x_dot[0]));
	double sigmoid = 1.0/(1.0+exp(-target.segment(0,2).norm()));
	sigmoid = pow(2.0*sigmoid-1.0, 2.0);
	Vector3d q_dot = (1.0-sigmoid) * q_dot_obj + sigmoid * q_dot_path;
	// take the yaw rotation only.
	x_dot[2] = q_dot[2];
	return x_dot;
}

Vector3d Navigation::nonlinear_DS(VectorXd target)
{
	// this function takes target position described in robot's frame
}