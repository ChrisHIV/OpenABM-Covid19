/*
 * params.h
 *
 *  Created on: 5 Mar 2020
 *      Author: hinchr
 */

#ifndef PARAMS_H_
#define PARAMS_H_

#include "constant.h"

/************************************************************************/
/****************************** Structures  *****************************/
/************************************************************************/

typedef struct{
	long rng_seed; 					// number used to seed the GSL RNG
	char input_param_file[INPUT_CHAR_LEN];	// path to input parameter file
	char output_file_dir[INPUT_CHAR_LEN];	// path to output directory
	int param_line_number;			// line number to be read from parameter file
	long param_id;					// id of the parameter set
	long n_total;  					// total number of people
	int days_of_interactions;		// the number of days of interactions to keep
	int end_time;				    // maximum end time
	int n_seed_infection;			// number of people seeded with the infections

	int mean_random_interactions[N_AGE_GROUPS]; // mean number of random interactions each day
	int mean_work_interactions[N_AGE_GROUPS];	// mean number of regular work interactions
	double daily_fraction_work;      			// fraction of daily work interactions
	double child_network_adults;				// fraction of adults in the child network
	double elderly_network_adults;				// fraction of adults in the elderly network

	double mean_infectious_period;  // mean period in days that people are infectious
	double sd_infectious_period;	// sd of period in days that people are infectious
	double infectious_rate;         // mean total number of people infected for a mean person

	double relative_susceptibility_child;	// relative susceptibility of children to adults per day (i.e. after adjust for no. interactions)
	double relative_susceptibility_elderly; // relative susceptibility of elderly to adults per day (i.e. after adjust for no. interactions)
	double adjusted_susceptibility_child;	// adjusted susceptibility of a child per interaction (derived from relative value and no. of interactions)
	double adjusted_susceptibility_elderly; // adjusted susceptibility of an elderly per interaction (derived from relative value and no. of interactions)

	double mean_time_to_symptoms;   // mean time from infection to symptoms
	double sd_time_to_symptoms;		// sd time from infection to symptoms

	double hospitalised_fraction[N_AGE_GROUPS];   // fraction of symptomatic patients requiring hospitalisation
	double fatality_fraction[N_AGE_GROUPS];  	  // fraction of hospitalised patients who die

	double mean_time_to_hospital;   // mean time from symptoms to hospital

	double mean_time_to_recover;	// mean time to recover after hospital
	double sd_time_to_recover;  	// sd time to recover after hospital
	double mean_time_to_death;		// mean time to death after hospital
	double sd_time_to_death;		// sd time to death after hospital

	double uk_house[UK_HOUSEHOLD_N_MAX];// ONS UK number of households with 1-6 person (in thousands)
	double uk_pop[N_AGE_GROUPS];		// ONS stratification of population (in millions)

	double fraction_asymptomatic;			// faction who are asymptomatic
	double asymptomatic_infectious_factor;  // relative infectiousness of asymptomatics
	double mean_asymptomatic_to_recovery;   // mean time to recovery for asymptomatics
	double sd_asymptomatic_to_recovery;     // sd of time to recovery for asymptomatics

	int quarantined_daily_interactions; 	// number of interactions a quarantined person has
	int hospitalised_daily_interactions; 	// number of interactions a hopsitalised person has

	int quarantine_days;					// number of days of previous contacts to quarantine
	double quarantine_fraction;				// fraction of people quarantine upon being asked to
	double self_quarantine_fraction;		// fraction of people who self-quarantine when show sypmtoms

	int quarantine_length_self;				// max length of quarantine if self-quarantine on symptoms
	int quarantine_length_traced;			// max length of quarantine if contact-traced
	int quarantine_length_positive;			// max length of quarantine if receive positive test result
	double quarantine_dropout_self;			// daily dropout rate if self-quarantined
	double quarantine_dropout_traced;		// daily dropout rate if contact-traced
	double quarantine_dropout_positive;     // daily dropout rate if receive positive test result
	int test_on_symptoms;					// carry out a test on those with symptoms
	int test_on_traced;						// carry out a test on those with positive test results
	int quarantine_on_traced;				// immediately quarantine those who are contact traced

	int test_insensititve_period;			// number of days until a test is sensitive (delay test of recent contacts)
	int test_result_wait;					// number of days to wait for a test result
	
	double app_users_fraction; 		// Proportion of the population that use the apps
	double seasonal_flu_rate; 		// Rate of seasonal flu
		
	int sys_write_individual; 		// Should an individual file be written to output?
	int sys_write_timeseries; 		// Should a time series file be written to output?  


} parameters;

/************************************************************************/
/******************************  Functions  *****************************/
/************************************************************************/

void check_params( parameters* );

#endif /* PARAMS_H_ */
