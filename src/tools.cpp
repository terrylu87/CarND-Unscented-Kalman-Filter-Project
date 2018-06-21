#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
    VectorXd rmse(4);
    rmse << 0,0,0,0;
    if(estimations.size() == 0
       || estimations.size() != ground_truth.size()){
        cout << "error input" << endl;
        return rmse;
    }
    VectorXd squared_residuals = rmse;
    VectorXd c = rmse;

    //accumulate squared residuals
    unsigned int i;
    for(i=0; i < estimations.size(); ++i){
        // ... your code here
        c = estimations[i] - ground_truth[i];
        c = c.array()*c.array();
        squared_residuals = squared_residuals + c;
    }
    rmse = squared_residuals / estimations.size();
    rmse = rmse.array().sqrt();

    //return the result
    return rmse;

}