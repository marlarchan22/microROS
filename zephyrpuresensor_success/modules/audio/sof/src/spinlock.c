// SPDX-License-Identifier: BSD-3-Clause
//
// Copyright(c) 2020 Intel Corporation. All rights reserved.
//
// Author: Tomasz Lauda <tomasz.lauda@linux.intel.com>

#include <sof/drivers/interrupt.h>
#if CONFIG_DEBUG_LOCKS
#include <sof/lib/uuid.h>
#endif
#include <sof/spinlock.h>

#include <stdint.h>

#if CONFIG_DEBUG_LOCKS

/* 9d346d98-203d-4791-baee-1770a03d4a71 */
DECLARE_SOF_UUID("spinlock", spinlock_uuid, 0x9d346d98, 0x203d, 0x4791,
		 0xba, 0xee, 0x17, 0x70, 0xa0, 0x3d, 0x4a, 0x71);

DECLARE_TR_CTX(sl_tr, SOF_UUID(spinlock_uuid), LOG_LEVEL_INFO);

#endif

uint32_t _spin_lock_irq(spinlock_t *lock)
{
	uint32_t flags;

	flags = interrupt_global_disable();
#if CONFIG_DEBUG_LOCKS
	lock_dbg_atomic++;
#endif
	spin_lock(lock);
#if CONFIG_DEBUG_LOCKS
	if (lock_dbg_atomic < DBG_LOCK_USERS)
		lock_dbg_user[lock_dbg_atomic - 1] = (lock)->user;
#endif
	return flags;
}

void _spin_unlock_irq(spinlock_t *lock, uint32_t flags, int line)
{
	_spin_unlock(lock, line);
#if CONFIG_DEBUG_LOCKS
	lock_dbg_atomic--;
#endif
	interrupt_global_enable(flags);
}
