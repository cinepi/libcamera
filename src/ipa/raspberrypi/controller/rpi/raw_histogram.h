#pragma once

#include "../algorithm.h"
#include "../metadata.h"

namespace RPiController {

class RawHistogram : public Algorithm
{
public:
	RawHistogram(Controller *controller);
	char const *name() const override;
	void process(StatisticsPtr &stats, Metadata *imageMetadata) override;
};

} /* namespace RPiController */
