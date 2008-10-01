/**
 * @file tpl_as_schedtable.c
 *
 * @internal
 *
 * @section desc File description
 *
 * Trampoline autosar extension software schedule tables API implementation
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_as_schedtable.h"
#include "tpl_as_st_kernel.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#ifndef NO_SCHEDTABLE
/**
 * Array of all schedule tables' full descriptors.
 *
 * Index in this array correspond to the #ScheduleTableType of the schedule
 * table. While it would be less time consuming to refer a schedule table
 * by a pointer to its descriptor, the AUTOSAR API requires a schedule table
 * to have an identifier. So a table of pointer is used. The size of this table
 * is static and known at compile time
 */
 /* MISRA RULE 27 VIOLATION: This variable is used only in this file
    but decalred in the configuration file, this is why it does not need
    to be declared as external in a header file */
extern P2VAR(tpl_schedule_table, OS_APPL_DATA, OS_VAR)
    tpl_schedtable_table[SCHEDTABLE_COUNT];
#endif

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * Start a schedule table at a relative date.
 *
 * see paragraph 8.4.8 page 80 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(StatusType, OS_CODE)  StartScheduleTableRel(
    VAR(ScheduleTableType, AUTOMATIC) sched_table_id,
    VAR(TickType, AUTOMATIC)          offset
)
{
    return tpl_start_schedule_table_rel_service(sched_table_id, offset);
}

/*
 * Start a schedule table at an absolute date.
 *
 * see paragraph 8.4.9 page 80 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(StatusType, OS_CODE)  StartScheduleTableAbs(
    VAR(ScheduleTableType, AUTOMATIC)   sched_table_id,
    VAR(TickType, AUTOMATIC)            tick_val
)
{
    return tpl_start_schedule_table_abs_service(sched_table_id, tick_val);
}


/*
 * Start a schedule table synchronized with global time
 *
 * see paragraph 8.4.12 page 84 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(StatusType, OS_CODE)  StartScheduleTableSynchron(
    VAR(ScheduleTableType, AUTOMATIC)   sched_table_id
)
{
    return tpl_start_schedule_table_synchron_service(sched_table_id);
}


/*
 * Stop a schedule table.
 *
 * see paragraph 8.4.10 page 81 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(StatusType, OS_CODE) StopScheduleTable(
    VAR(ScheduleTableType, AUTOMATIC)   sched_table_id
)
{
    return tpl_stop_schedule_table_service(sched_table_id);
}

/*
 * Switch the processing from one schedule table to another.
 *
 * see paragraph 8.4.11 page 83 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(StatusType, OS_CODE) NextScheduleTable(
    VAR(ScheduleTableType, AUTOMATIC)   current_st_id,
    VAR(ScheduleTableType, AUTOMATIC)   next_st_id
)
{
    return tpl_next_schedule_table_service(current_st_id, next_st_id);
}


/**
 * Get the status of a schedule table
 *
 * see paragraph 8.4.15 page 86 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(StatusType, OS_CODE) GetScheduleTableStatus(
    VAR(ScheduleTableType, AUTOMATIC)           sched_table_id,
    VAR(ScheduleTableStatusRefType, AUTOMATIC)  status)
{
    return tpl_get_schedule_table_status_service(sched_table_id, status);
}



/**
 *  Synchronize a schedule table with global time
 *
 * see paragraph 8.4.13 page 84 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(StatusType, OS_CODE) SyncScheduleTable(
    VAR(ScheduleTableType, AUTOMATIC)   sched_table_id,
    VAR(TickType, AUTOMATIC)            value)
{
    return tpl_sync_schedule_table_service(sched_table_id, value);
}


/**
 *  Set a schedule table asynchrone to global time
 *
 * see paragraph 8.4.14 page 85 of
 * AUTOSAR/Specification of the Operating System v3.0
 */
FUNC(StatusType, OS_CODE) SetScheduleTableAsync(
    VAR(ScheduleTableType, AUTOMATIC) sched_table_id
)
{
    return tpl_set_schedule_table_async(sched_table_id);
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


/* End of file tpl_as_schedtable.c */
