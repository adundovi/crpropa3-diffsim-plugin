/// Plugin for CRPropa that simplifies test-particle simulations
/// for calculating diffusion coefficients
///

#include <crpropa/ParticleID.h>
#include <crpropa/Source.h>
#include <crpropa/module/ParticleCollector.h>

crpropa::ParticleCollector initHomogeneousDistribution(
        std::size_t N, double E, double boxsize);

/*
/// A custom C++ module
class MyModule : public crpropa::Module
{
public:
	/// The parent's constructor need to be called on initialization!
	MyModule();
	void process(crpropa::Candidate *candidate) const;
};


/// A custom source feature
class AddMyProperty: public crpropa::SourceFeature
{
public:
	/// The parent's constructor need to be called on initialization!
	AddMyProperty();
	void prepareCandidate(crpropa::Candidate &candidate) const;
};
*/
