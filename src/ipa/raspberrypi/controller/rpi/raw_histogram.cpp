/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Copyright (C) 2020, Raspberry Pi Ltd
 *
 * focus.cpp - focus algorithm
 */
#include <stdint.h>

#include <libcamera/base/log.h>

#include "../raw_histogram_status.h"
#include "raw_histogram.h"
#include <linux/bcm2835-isp.h>

using namespace RPiController;
using namespace libcamera;

LOG_DEFINE_CATEGORY(RPiRawHistogram)

#define NAME "rpi.raw_histogram"

RawHistogram::RawHistogram(Controller *controller)
	: Algorithm(controller)
{
}

char const *RawHistogram::name() const
{
	return NAME;
}

void RawHistogram::process(StatisticsPtr &stats, Metadata *imageMetadata)
{
	RawHistogram status;
	status.lo[0] = stats->hist[0].r_hist[0];
	status.lo[1] = stats->hist[0].g_hist[0];
	status.lo[2] = stats->hist[0].b_hist[0];

	status.lo[0] = stats->hist[0].r_hist[NUM_HISTOGRAM_BINS - 1];
	status.lo[1] = stats->hist[0].g_hist[NUM_HISTOGRAM_BINS - 1];
	status.lo[2] = stats->hist[0].b_hist[NUM_HISTOGRAM_BINS - 1];
	
	imageMetadata->set("raw_histogram.status", status);
}

/* Register algorithm with the system. */
static Algorithm *create(Controller *controller)
{
	return new RawHistogram(controller);
}
static RegisterAlgorithm reg(NAME, &create);
