#ifndef JOINT_H
#define JOINT_H

#include "Frame.hpp"
#include "DynamicTransformation.hpp"
#include <base/JointLimitRange.hpp>
#include <base/JointState.hpp>
#include <base/JointTransform.hpp>

namespace smurf{
    
    
    class Joint : public DynamicTransformation
    {
    public:
        
        Joint(const std::string &name, Frame* sourceFrame, Frame* targetFrame, const std::string &provider, const std::string &port, const std::string &driverName, base::JointLimitRange &limits, const Eigen::Affine3d &sourceToAxis);
        
        Joint(const std::string &name, Frame* sourceFrame, Frame* targetFrame, const std::string& provider, const std::string& port, const std::string& driverName, base::JointLimitRange& limits, const Eigen::Affine3d& sourceToAxis, const Eigen::Affine3d& parentToJointOrigin); 
        
        Joint(const std::string &name, Frame* sourceFrame, Frame* targetFrame, const std::string& provider, const std::string& port, const std::string& driverName, base::JointLimitRange& limits, const Eigen::Affine3d& sourceToAxis, const Eigen::Affine3d& parentToJointOrigin, urdf::JointSharedPtr jointModel);
        
        Joint(Frame* sourceFrame, Frame* targetFrame, const std::string &provider, const std::string &port, const std::string &driverName, base::JointLimitRange &limits, const Eigen::Affine3d &sourceToAxis);
        
        Joint(Frame* sourceFrame, Frame* targetFrame, const std::string& provider, const std::string& port, const std::string& driverName, base::JointLimitRange& limits, const Eigen::Affine3d& sourceToAxis, const Eigen::Affine3d& parentToJointOrigin); 
        
        Joint(Frame* sourceFrame, Frame* targetFrame, const std::string& provider, const std::string& port, const std::string& driverName, base::JointLimitRange& limits, const Eigen::Affine3d& sourceToAxis, const Eigen::Affine3d& parentToJointOrigin, urdf::JointSharedPtr jointModel);

        const Eigen::Affine3d &getSourceToAxis() const;
        
        const Eigen::Affine3d &getParentToJointOrigin() const;
        
        void setParentToJointOrigin(const Eigen::Affine3d inParentToJointOrigin);
        
        urdf::JointSharedPtr getJointModel() const;

        std::pair<double, double> getPositionLimits() const;

        std::pair<double, double> getEffortLimits() const;

        std::pair<double, double> getSpeedLimits() const;
        
    protected:
        
        /**
         * Name of the rock task that provides 
         * the driver for this joint.
         * 
         * e.g. "servo_dynamixel::Task"
         * */
        std::string driverName;
        
        /**
         * Physical limits of the joint.
         * */
        base::JointLimitRange limits;
        
        /**
         * Transformation from the source frame
         * to the joint axis.
         * */
        Eigen::Affine3d sourceToAxis;
        
        Eigen::Affine3d parentToJointOrigin;
        
        /**
         * Urdf data of the joint
         * 
         */
        urdf::JointSharedPtr jointModel;
        
    };
    

    

    
};

#endif // JOINT_H
