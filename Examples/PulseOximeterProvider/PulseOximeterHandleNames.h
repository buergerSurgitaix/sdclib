/*
 * PulseOximeterHandleNames.h
 *
 *  Created on: Jun 19, 2019
 *      Author: sebastian
 */

#ifndef EXAMPLES_PULSEOXIMETERPROVIDER_PULSEOXIMETERHANDLENAMES_H_
#define EXAMPLES_PULSEOXIMETERPROVIDER_PULSEOXIMETERHANDLENAMES_H_



const std::string PULSE_OXIMETER_MDS_HANDLE("MDC_DEV_PULS_OXIM_MDS");
const std::string PULSE_OXIMETER_VMD_HANDLE("MDC_DEV_PULS_OXIM_VMD");
const std::string PULSE_OXIMETER_PULS_CHAN_HANDLE("MDC_DEV_PULS_OXIM_PULS_CHAN");
const std::string PULSE_OXIMETER_PULS_SAT_O2_CHAN_HANDLE("MDC_DEV_PULS_OXIM_SAT_O2_CHAN");
const std::string DIMENSION_PERCENTAGE("MDC_DIM_PERCENT");
const std::string DIMENSION_BEATS_PER_MIN("MDC_DIM_BEAT_PER_MIN");
const std::string PULSE_OXIMETER_SAT_O2_GET_HANDLE("MDC_PULS_OXIM_SAT_O2");
const std::string PULSE_OXIMETER_PULSE_RATE_GET_HANDLE("MDC_PULS_OXIM_PULS_RATE");
const std::string PULSE_OXIMETER_SAT_O2_UPPER_ALARM_LIMIT_SET_HANDLE("MDC_DEV_PULS_OXIM_SAT_O2_SET_AL_LIMIT_UPPER");
const std::string PULSE_OXIMETER_SAT_O2_LOWER_ALARM_LIMIT_SET_HANDLE("MDC_DEV_PULS_OXIM_SAT_O2_SET_AL_LIMIT_LOWER");
const std::string PULSE_OXIMETER_PULSE_RATE_UPPER_ALARM_LIMIT_SET_HANDLE("MDC_DEV_PULS_OXIM_PULSE_RATE_SET_AL_LIMIT_UPPER");
const std::string PULSE_OXIMETER_PULSE_RATE_LOWER_ALARM_LIMIT_SET_HANDLE("MDC_DEV_PULS_OXIM_PULSE_RATE_SET_AL_LIMIT_LOWER");
const std::string PULSE_OXIMETER_PULSE_RATE_LIMIT_ALERT_HANDLE("MDC_DEV_PULS_OXIM_PULS_AL_LIMIT_STAT");
const std::string PULSE_OXIMETER_SAT_O2_LIMIT_ALERT_HANDLE("MDC_DEV_PULS_OXIM_SAT_O2_AL_LIMIT_STAT");
const std::string PULSE_OXIMETER_PULSE_RATE_LIMIT_ALERT_SIGNAL_HANDLE("MDC_DEV_PULSE_OXIM_PULS_AL_LIMIT_SIGN");
const std::string PULSE_OXIMETER_SAT_O2_LIMIT_ALERT_SIGNAL_HANDLE("MDC_DEV_PULSE_OXIM_SAT_O2_AL_LIMIT_SIGN");
const int DEFAULT_UPPER_PULSE_RATE_ALARM_LIMIT(90);
const int DEFAULT_LOWER_PULSE_RATE_ALARM_LIMIT(60);
const int DEFAULT_UPPER_SAT_O2_ALARM_LIMIT(99);
const int DEFAULT_LOWER_SAT_O2_ALARM_LIMIT(95);

#endif /* EXAMPLES_PULSEOXIMETERPROVIDER_PULSEOXIMETERHANDLENAMES_H_ */
