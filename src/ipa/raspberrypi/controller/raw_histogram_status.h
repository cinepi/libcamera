#pragma once

#include <linux/bcm2835-isp.h>

struct RawHistogramStatus {
	int32_t r[NUM_HISTOGRAM_BINS];
    int32_t g[NUM_HISTOGRAM_BINS];
    int32_t b[NUM_HISTOGRAM_BINS];
};
