#include <Simbody.h>
using namespace SimTK;

int main()
{
	MultibodySystem bicycle;
	SimbodyMatterSubsystem matter(bicycle);
	GeneralForceSubsystem forces(bicycle);
	Force::UniformGravity gravity(forces, matter, Vec(0, 0, 9.8));

    // Properties.
    // -----------
    // All distances are in meters.
    double rearWheelRadius = 0.3;
    double frontWheelRadius = 0.35;
    double 

	// Body's.
	// -------

	// Rear wheel.
	Body::Rigid rearWheel(MassProperties(2.0, Vec3(),
                Inertia(0.0603, 0.12, 0.0));
	rearWheel.addDecoration(Transform(), Dec());

    // Rear frame.
	Body::Rigid rearFrame(MassProperties(85.0, ,
            Inertia(7.1782, 11.0, 4.8218));
	rearFrame.addDecoration(Transform(), Dec());

	// Front frame.
	Body::Rigid frontFrame(MassProperties(4.0, Vec3(0.470727, 0, -0.4778288),
            Inertia(0.0584134, 0.06, 0.0075866)));
	frontFrame.addDecoration(Transform(), Dec());

	// Front wheel.
	Body::Rigid frontWheel(MassProperties(3.0, Vec3(),
            Inertia(0.1405, 0.28, 0.0)));
	frontWheel.addDecoration(Transform(), Dec());

	// MobilizedBody's.
	// ----------------
	MobilizedBody::NoSlipWheel mbRearWheel(
		matter.Ground(),
		Transform(Vec3(0)),
		rearWheel,
		Transform(Vec3()));
	MobilizedBody::Pin mbRearFrame(
		mbRearWheel,
		Transform(Vec3(0)),
		rearFrame,
		Transform(Vec3()));
	MobilizedBody::Pin mbFrontFrame(
		mbRearFrame,
		Transform(Vec3(0)),
		frontFrame,
		Transform(Vec3()));
	MobilizedBody::Pin mbFrontWheel(
		mbFrontFrame,
		Transform(Vec3(0)),
		frontWheel,
		Transform(Vec3()));

	// Constraints
	// -----------

	// Front wheel rolling/non-holonomic/velocity constraint:
	// The front wheel 
	// Use a SpeedCoupler, or NoSplip1D

	// Front wheel contact constraint:
	// Use a CoordinateCoupler; probably not.
    
	

	return EXIT_SUCCESS;
};
