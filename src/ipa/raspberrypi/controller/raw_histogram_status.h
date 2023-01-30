#pragma once

#include <linux/bcm2835-isp.h>

struct RawHistogramStatus {
	int32_t lo[3];
    int32_t hi[3];
};
