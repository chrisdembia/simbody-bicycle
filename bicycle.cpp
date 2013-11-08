#include <Simbody.h>
using namespace SimTK;

int main()
{
	MultibodySystem bicycle;
	SimbodyMatterSubsystem matter(bicycle);
	GeneralForceSubsystem forces(bicycle);
	Force::UniformGravity gravity(forces, matter, Vec(0, 0, 9.8));

	// Body's.
	// -------

	// Rear wheel.
	Body::Rigid rearWheel(MassProperties());
	rearWheel.addDecoration(Transform(), Dec());
	
	// Rear frame.
	Body::Rigid rearFrame(MassProperties());
	rearFrame.addDecoration(Transform(), Dec());

	// Front frame.
	Body::Rigid frontFrame(MassProperties());
	frontFrame.addDecoration(Transform(), Dec());

	// Front wheel.
	Body::Rigid frontWheel(MassProperties());
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
	// Use a CoordinateCoupler
	

	return EXIT_SUCCESS;
};
