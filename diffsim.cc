#include "diffsim.h"

#include <string>
#include <memory>

crpropa::ParticleCollector initHomogeneousDistribution(
		std::size_t N, double E, double boxsize) {
		
	crpropa::Source source {};
	source.add(new crpropa::SourceEnergy(E));
	source.add(new crpropa::SourceIsotropicEmission());
	source.add(new crpropa::SourceParticleType(crpropa::nucleusId(1,1)));
	source.add(new crpropa::SourceUniformBox(
		crpropa::Vector3d(-boxsize/2), crpropa::Vector3d(boxsize)));

	auto initDist = crpropa::ParticleCollector();
		
	for (int i = 0; i < N; ++i ) {
		auto c = source.getCandidate();
		initDist.process(c);
	}

    return initDist;
}

/*
const std::string myPropertyName = "counter";

// The parent's constructor need to be called on initialization!
MyModule::MyModule() : crpropa::Module()
{
	setDescription("MyPlugin::MyModule");
}

void MyModule::process(crpropa::Candidate *candidate) const
{
	// To enable parallelization, the modules have to be stateless - the
	// process method should thus not modify internal variables!
	std::cout << "MyPlugin::MyModule::process() called\n";
	if(candidate->hasProperty(myPropertyName)) {
		uint32_t v = candidate->getProperty(myPropertyName);
		std::cout << " My property: " << myPropertyName << " = " <<  v << std::endl;
		candidate->setProperty(myPropertyName, crpropa::Variant::fromUInt32(v + 1));
	}
}

// ------------------------------------------------------------------
// The parent's constructor need to be called on initialization!
AddMyProperty::AddMyProperty() : crpropa::SourceFeature()
{
	description = "AddMyProperty: Adds my property to the candidate";
}
void AddMyProperty::prepareCandidate(crpropa::Candidate &candidate) const
{
	candidate.setProperty(myPropertyName, crpropa::Variant::fromUInt32(0));
}
*/
