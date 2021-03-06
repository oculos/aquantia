/* ****************************************************************
 * Copyright 2011 VMware, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * ****************************************************************/

#include "vmkapi.h"
#include "vmklinux_version.h"
#include <linux/module.h>
/* NOTE: __namespace.h is generated by the build from the driver's .sc file. */
#include "__namespace.h"

#ifndef MODULE
#error "You can only compile and link vmklinux_module with modules, which" \
       "means that MODULE has to be defined when compiling it..."
#endif

VMK_LICENSE_INFO(VMK_MODULE_LICENSE_GPLV2);
MODULE_VERSION2(VMKLNX_STRINGIFY(PRODUCT_VERSION), VMKLNX_MY_NAMESPACE_VERSION);

/*
 * All vmkdriver modules are built using the latest vmakpi interface.
 */
VMK_NAMESPACE_REQUIRED(VMK_NAMESPACE_VMKAPI, VMK_NAMESPACE_CURRENT_VERSION);
#if VMKAPI_REVISION >= VMK_REVISION_FROM_NUMBERS(2, 2, 0, 0) && \
    defined(VMK_DEVKIT_USES_BINARY_INCOMPATIBLE_APIS)
VMK_NAMESPACE_REQUIRED(VMK_NAMESPACE_VMKAPI_INCOMPAT,
                       VMK_NAMESPACE_INCOMPAT_CURRENT_VERSION);
#endif

vmk_ModuleID vmkshim_module_id;

int
vmk_early_init_module(void)
{
   VMK_ReturnStatus vmk_status;

   vmk_status = vmk_ModuleRegister(&vmkshim_module_id, VMKAPI_REVISION);
   if (vmk_status != VMK_OK) {
      vmk_WarningMessage("Registration failed (%#x): %s",
                          vmk_status, vmk_StatusToString(vmk_status));
      return vmk_status;
   }

   return 0;
}

int
vmk_late_cleanup_module(void)
{
   return 0;
}

/*
 * Symbols passed in directly from iscsi_linux without the need for a shim function.
 */

VMK_MODULE_EXPORT_ALIAS(iscsi_release_device_host);
VMK_MODULE_EXPORT_ALIAS(iscsi_alloc_session);
VMK_MODULE_EXPORT_ALIAS(iscsi_add_session);
VMK_MODULE_EXPORT_ALIAS(iscsi_create_session);
VMK_MODULE_EXPORT_ALIAS(iscsi_offline_session);
VMK_MODULE_EXPORT_ALIAS(iscsi_remove_session);
VMK_MODULE_EXPORT_ALIAS(iscsi_free_session);
VMK_MODULE_EXPORT_ALIAS(iscsi_destroy_session);
VMK_MODULE_EXPORT_ALIAS(iscsi_create_conn);
VMK_MODULE_EXPORT_ALIAS(iscsi_destroy_conn);
VMK_MODULE_EXPORT_ALIAS(iscsi_unblock_session);
VMK_MODULE_EXPORT_ALIAS(iscsi_block_session);
VMK_MODULE_EXPORT_ALIAS(iscsi_conn_error);
VMK_MODULE_EXPORT_ALIAS(iscsi_recv_pdu);
VMK_MODULE_EXPORT_ALIAS(iscsi_scan_target);
VMK_MODULE_EXPORT_ALIAS(iscsi_user_scan);
VMK_MODULE_EXPORT_ALIAS(iscsi_if_create_session_done);
VMK_MODULE_EXPORT_ALIAS(iscsi_if_destroy_session_done);
VMK_MODULE_EXPORT_ALIAS(iscsi_if_connection_start_done);
VMK_MODULE_EXPORT_ALIAS(iscsi_if_connection_stop_done);
VMK_MODULE_EXPORT_ALIAS(iscsi_register_transport);
VMK_MODULE_EXPORT_ALIAS(iscsi_unregister_transport);
VMK_MODULE_EXPORT_ALIAS(iscsi_register_host);
VMK_MODULE_EXPORT_ALIAS(iscsi_unregister_host);
VMK_MODULE_EXPORT_ALIAS(iscsi_sdevice_to_session);
VMK_MODULE_EXPORT_ALIAS(iscsi_lookup_session);
