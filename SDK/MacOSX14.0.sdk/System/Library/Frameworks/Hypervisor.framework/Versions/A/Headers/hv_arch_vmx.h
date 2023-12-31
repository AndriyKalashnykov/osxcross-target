//
//  hv_arch_vmx.h
//  Hypervisor
//
//  Created by Sebastian Gregorzyk on 2/3/14.
//  Copyright © 2021-2023 Apple Inc. All rights reserved.
//

#ifndef __HYPERVISOR_HV_ARCH_VMX__
#define __HYPERVISOR_HV_ARCH_VMX__

#ifdef __x86_64__

#include <Hypervisor/hv_base.h>

#define    __VMCS_HOST_RSP    0x00006c14

#ifndef __ASSEMBLER__
OS_ASSUME_NONNULL_BEGIN

__BEGIN_DECLS

enum {
    VMCS_VPID                            = 0x00000000,
    VMCS_CTRL_POSTED_INT_N_VECTOR        = 0x00000002,
    VMCS_CTRL_EPTP_INDEX                = 0x00000004,
    VMCS_GUEST_ES                        = 0x00000800,
    VMCS_GUEST_CS                        = 0x00000802,
    VMCS_GUEST_SS                        = 0x00000804,
    VMCS_GUEST_DS                        = 0x00000806,
    VMCS_GUEST_FS                        = 0x00000808,
    VMCS_GUEST_GS                        = 0x0000080a,
    VMCS_GUEST_LDTR                        = 0x0000080c,
    VMCS_GUEST_TR                        = 0x0000080e,
    VMCS_GUEST_INT_STATUS                = 0x00000810,
    VMCS_GUESTPML_INDEX                    = 0x00000812,
    VMCS_HOST_ES                        = 0x00000c00,
    VMCS_HOST_CS                        = 0x00000c02,
    VMCS_HOST_SS                        = 0x00000c04,
    VMCS_HOST_DS                        = 0x00000c06,
    VMCS_HOST_FS                        = 0x00000c08,
    VMCS_HOST_GS                        = 0x00000c0a,
    VMCS_HOST_TR                        = 0x00000c0c,
    VMCS_CTRL_IO_BITMAP_A                = 0x00002000,
    VMCS_CTRL_IO_BITMAP_B                = 0x00002002,
    VMCS_CTRL_MSR_BITMAPS                = 0x00002004,
    VMCS_CTRL_VMEXIT_MSR_STORE_ADDR        = 0x00002006,
    VMCS_CTRL_VMEXIT_MSR_LOAD_ADDR        = 0x00002008,
    VMCS_CTRL_VMENTRY_MSR_LOAD_ADDR        = 0x0000200a,
    VMCS_CTRL_EXECUTIVE_VMCS_PTR        = 0x0000200c,
    VMCS_CTRL_PML_ADDR                    = 0x0000200e,
    VMCS_CTRL_TSC_OFFSET                = 0x00002010,
    VMCS_CTRL_VIRTUAL_APIC                = 0x00002012,
    VMCS_CTRL_APIC_ACCESS                = 0x00002014,
    VMCS_CTRL_POSTED_INT_DESC_ADDR        = 0x00002016,
    VMCS_CTRL_VMFUNC_CTRL                = 0x00002018,
    VMCS_CTRL_EPTP                        = 0x0000201a,
    VMCS_CTRL_EOI_EXIT_BITMAP_0            = 0x0000201c,
    VMCS_CTRL_EOI_EXIT_BITMAP_1            = 0x0000201e,
    VMCS_CTRL_EOI_EXIT_BITMAP_2            = 0x00002020,
    VMCS_CTRL_EOI_EXIT_BITMAP_3            = 0x00002022,
    VMCS_CTRL_EPTP_LIST_ADDR            = 0x00002024,
    VMCS_CTRL_VMREAD_BITMAP_ADDR        = 0x00002026,
    VMCS_CTRL_VMWRITE_BITMAP_ADDR        = 0x00002028,
    VMCS_CTRL_VIRT_EXC_INFO_ADDR        = 0x0000202a,
    VMCS_CTRL_XSS_EXITING_BITMAP        = 0x0000202c,
    VMCS_CTRL_ENCLS_EXITING_BITMAP        = 0x0000202e,
    VMCS_CTRL_SPP_TABLE                    = 0x00002030,
    VMCS_CTRL_TSC_MULTIPLIER            = 0x00002032,
    VMCS_CTRL_ENCLV_EXITING_BITMAP        = 0x00002036,
    VMCS_GUEST_PHYSICAL_ADDRESS            = 0x00002400,
    VMCS_GUEST_LINK_POINTER                = 0x00002800,
    VMCS_GUEST_IA32_DEBUGCTL            = 0x00002802,
    VMCS_GUEST_IA32_PAT                    = 0x00002804,
    VMCS_GUEST_IA32_EFER                = 0x00002806,
    VMCS_GUEST_IA32_PERF_GLOBAL_CTRL    = 0x00002808,
    VMCS_GUEST_PDPTE0                    = 0x0000280a,
    VMCS_GUEST_PDPTE1                    = 0x0000280c,
    VMCS_GUEST_PDPTE2                    = 0x0000280e,
    VMCS_GUEST_PDPTE3                    = 0x00002810,
    VMCS_GUEST_IA32_BNDCFGS                = 0x00002812,
    VMCS_GUEST_IA32_RTIT_CTL            = 0x00002814,
    VMCS_GUEST_IA32_PKRS                = 0x00002818,
    VMCS_HOST_IA32_PAT                    = 0x00002c00,
    VMCS_HOST_IA32_EFER                    = 0x00002c02,
    VMCS_HOST_IA32_PERF_GLOBAL_CTRL        = 0x00002c04,
    VMCS_HOST_IA32_PKRS                    = 0x00002c06,
    VMCS_CTRL_PIN_BASED                    = 0x00004000,
    VMCS_CTRL_CPU_BASED                    = 0x00004002,
    VMCS_CTRL_EXC_BITMAP                = 0x00004004,
    VMCS_CTRL_PF_ERROR_MASK                = 0x00004006,
    VMCS_CTRL_PF_ERROR_MATCH            = 0x00004008,
    VMCS_CTRL_CR3_COUNT                    = 0x0000400a,
    VMCS_CTRL_VMEXIT_CONTROLS            = 0x0000400c,
    VMCS_CTRL_VMEXIT_MSR_STORE_COUNT    = 0x0000400e,
    VMCS_CTRL_VMEXIT_MSR_LOAD_COUNT        = 0x00004010,
    VMCS_CTRL_VMENTRY_CONTROLS            = 0x00004012,
    VMCS_CTRL_VMENTRY_MSR_LOAD_COUNT    = 0x00004014,
    VMCS_CTRL_VMENTRY_IRQ_INFO            = 0x00004016,
    VMCS_CTRL_VMENTRY_EXC_ERROR            = 0x00004018,
    VMCS_CTRL_VMENTRY_INSTR_LEN            = 0x0000401a,
    VMCS_CTRL_TPR_THRESHOLD                = 0x0000401c,
    VMCS_CTRL_CPU_BASED2                = 0x0000401e,
    VMCS_CTRL_PLE_GAP                    = 0x00004020,
    VMCS_CTRL_PLE_WINDOW                = 0x00004022,
    VMCS_RO_INSTR_ERROR                    = 0x00004400,
    VMCS_RO_EXIT_REASON                    = 0x00004402,
    VMCS_RO_VMEXIT_IRQ_INFO                = 0x00004404,
    VMCS_RO_VMEXIT_IRQ_ERROR            = 0x00004406,
    VMCS_RO_IDT_VECTOR_INFO                = 0x00004408,
    VMCS_RO_IDT_VECTOR_ERROR            = 0x0000440a,
    VMCS_RO_VMEXIT_INSTR_LEN            = 0x0000440c,
    VMCS_RO_VMX_INSTR_INFO                = 0x0000440e,
    VMCS_GUEST_ES_LIMIT                    = 0x00004800,
    VMCS_GUEST_CS_LIMIT                    = 0x00004802,
    VMCS_GUEST_SS_LIMIT                    = 0x00004804,
    VMCS_GUEST_DS_LIMIT                    = 0x00004806,
    VMCS_GUEST_FS_LIMIT                    = 0x00004808,
    VMCS_GUEST_GS_LIMIT                    = 0x0000480a,
    VMCS_GUEST_LDTR_LIMIT                = 0x0000480c,
    VMCS_GUEST_TR_LIMIT                    = 0x0000480e,
    VMCS_GUEST_GDTR_LIMIT                = 0x00004810,
    VMCS_GUEST_IDTR_LIMIT                = 0x00004812,
    VMCS_GUEST_ES_AR                    = 0x00004814,
    VMCS_GUEST_CS_AR                    = 0x00004816,
    VMCS_GUEST_SS_AR                    = 0x00004818,
    VMCS_GUEST_DS_AR                    = 0x0000481a,
    VMCS_GUEST_FS_AR                    = 0x0000481c,
    VMCS_GUEST_GS_AR                    = 0x0000481e,
    VMCS_GUEST_LDTR_AR                    = 0x00004820,
    VMCS_GUEST_TR_AR                    = 0x00004822,
    VMCS_GUEST_INTERRUPTIBILITY            = 0x00004824,
    VMCS_GUEST_IGNORE_IRQ = VMCS_GUEST_INTERRUPTIBILITY,
    VMCS_GUEST_ACTIVITY_STATE            = 0x00004826,
    VMCS_GUEST_SMBASE                    = 0x00004828,
    VMCS_GUEST_IA32_SYSENTER_CS            = 0x0000482a,
    VMCS_GUEST_VMX_TIMER_VALUE            = 0x0000482e,
    VMCS_HOST_IA32_SYSENTER_CS            = 0x00004c00,
    VMCS_CTRL_CR0_MASK                    = 0x00006000,
    VMCS_CTRL_CR4_MASK                    = 0x00006002,
    VMCS_CTRL_CR0_SHADOW                = 0x00006004,
    VMCS_CTRL_CR4_SHADOW                = 0x00006006,
    VMCS_CTRL_CR3_VALUE0                = 0x00006008,
    VMCS_CTRL_CR3_VALUE1                = 0x0000600a,
    VMCS_CTRL_CR3_VALUE2                = 0x0000600c,
    VMCS_CTRL_CR3_VALUE3                = 0x0000600e,
    VMCS_RO_EXIT_QUALIFIC                = 0x00006400,
    VMCS_RO_IO_RCX                        = 0x00006402,
    VMCS_RO_IO_RSI                        = 0x00006404,
    VMCS_RO_IO_RDI                        = 0x00006406,
    VMCS_RO_IO_RIP                        = 0x00006408,
    VMCS_RO_GUEST_LIN_ADDR                = 0x0000640a,
    VMCS_GUEST_CR0                        = 0x00006800,
    VMCS_GUEST_CR3                        = 0x00006802,
    VMCS_GUEST_CR4                        = 0x00006804,
    VMCS_GUEST_ES_BASE                    = 0x00006806,
    VMCS_GUEST_CS_BASE                    = 0x00006808,
    VMCS_GUEST_SS_BASE                    = 0x0000680a,
    VMCS_GUEST_DS_BASE                    = 0x0000680c,
    VMCS_GUEST_FS_BASE                    = 0x0000680e,
    VMCS_GUEST_GS_BASE                    = 0x00006810,
    VMCS_GUEST_LDTR_BASE                = 0x00006812,
    VMCS_GUEST_TR_BASE                    = 0x00006814,
    VMCS_GUEST_GDTR_BASE                = 0x00006816,
    VMCS_GUEST_IDTR_BASE                = 0x00006818,
    VMCS_GUEST_DR7                        = 0x0000681a,
    VMCS_GUEST_RSP                        = 0x0000681c,
    VMCS_GUEST_RIP                        = 0x0000681e,
    VMCS_GUEST_RFLAGS                    = 0x00006820,
    VMCS_GUEST_DEBUG_EXC                = 0x00006822,
    VMCS_GUEST_SYSENTER_ESP                = 0x00006824,
    VMCS_GUEST_SYSENTER_EIP                = 0x00006826,
    VMCS_GUEST_IA32_S_CET                = 0x00006828,
    VMCS_GUEST_SSP                        = 0x0000682a,
    VMCS_GUEST_IA32_INTR_SSP_TABLE_ADDR    = 0x0000682c,
    VMCS_HOST_CR0                        = 0x00006c00,
    VMCS_HOST_CR3                        = 0x00006c02,
    VMCS_HOST_CR4                        = 0x00006c04,
    VMCS_HOST_FS_BASE                    = 0x00006c06,
    VMCS_HOST_GS_BASE                    = 0x00006c08,
    VMCS_HOST_TR_BASE                    = 0x00006c0a,
    VMCS_HOST_GDTR_BASE                    = 0x00006c0c,
    VMCS_HOST_IDTR_BASE                    = 0x00006c0e,
    VMCS_HOST_IA32_SYSENTER_ESP            = 0x00006c10,
    VMCS_HOST_IA32_SYSENTER_EIP            = 0x00006c12,
    VMCS_HOST_RSP                        = __VMCS_HOST_RSP,
    VMCS_HOST_RIP                        = 0x00006c16,
    VMCS_HOST_IA32_S_CET                = 0x00006c18,
    VMCS_HOST_SSP                        = 0x00006c1a,
    VMCS_HOST_IA32_INTR_SSP_TABLE_ADDR    = 0x00006c1c,
    VMCS_MAX                            = 0x00006d00,
    VMCS_INVALID                        = VMCS_MAX
};

enum {
    VMX_BASIC_TRUE_CTLS                    = (1ull << 55)
};

enum {
    // Pin-Based VM-Execution Controls
    PIN_BASED_INTR                        = (1u << 0),
    PIN_BASED_NMI                        = (1u << 3),
    PIN_BASED_VIRTUAL_NMI                = (1u << 5),
    PIN_BASED_PREEMPTION_TIMER            = (1u << 6),
    PIN_BASED_POSTED_INTR                = (1u << 7),

    // Primary Processor-Based VM-Execution Controls
    CPU_BASED_IRQ_WND                    = (1u << 2),
    CPU_BASED_TSC_OFFSET                = (1u << 3),
    CPU_BASED_HLT                        = (1u << 7),
    CPU_BASED_INVLPG                    = (1u << 9),
    CPU_BASED_MWAIT                        = (1u << 10),
    CPU_BASED_RDPMC                        = (1u << 11),
    CPU_BASED_RDTSC                        = (1u << 12),
    CPU_BASED_CR3_LOAD                    = (1u << 15),
    CPU_BASED_CR3_STORE                    = (1u << 16),
    CPU_BASED_CR8_LOAD                    = (1u << 19),
    CPU_BASED_CR8_STORE                    = (1u << 20),
    CPU_BASED_TPR_SHADOW                = (1u << 21),
    CPU_BASED_VIRTUAL_NMI_WND            = (1u << 22),
    CPU_BASED_MOV_DR                    = (1u << 23),
    CPU_BASED_UNCOND_IO                    = (1u << 24),
    CPU_BASED_IO_BITMAPS                = (1u << 25),
    CPU_BASED_MTF                        = (1u << 27),
    CPU_BASED_MSR_BITMAPS                = (1u << 28),
    CPU_BASED_MONITOR                    = (1u << 29),
    CPU_BASED_PAUSE                        = (1u << 30),
    CPU_BASED_SECONDARY_CTLS            = (1u << 31),

    // Secondary Processor-Based VM-Execution Controls
    CPU_BASED2_VIRTUAL_APIC                = (1u << 0),
    CPU_BASED2_EPT                        = (1u << 1),
    CPU_BASED2_DESC_TABLE                = (1u << 2),
    CPU_BASED2_RDTSCP                    = (1u << 3),
    CPU_BASED2_X2APIC                    = (1u << 4),
    CPU_BASED2_VPID                        = (1u << 5),
    CPU_BASED2_WBINVD                    = (1u << 6),
    CPU_BASED2_UNRESTRICTED                = (1u << 7),
    CPU_BASED2_APIC_REG_VIRT            = (1u << 8),
    CPU_BASED2_VIRT_INTR_DELIVERY        = (1u << 9),
    CPU_BASED2_PAUSE_LOOP                = (1u << 10),
    CPU_BASED2_RDRAND                    = (1u << 11),
    CPU_BASED2_INVPCID                    = (1u << 12),
    CPU_BASED2_VMFUNC                    = (1u << 13),
    CPU_BASED2_VMCS_SHADOW                = (1u << 14),
    CPU_BASED2_ENCLS_EXIT_MAP            = (1u << 15),
    CPU_BASED2_RDSEED                    = (1u << 16),
    CPU_BASED2_PML                        = (1u << 17),
    CPU_BASED2_EPT_VE                    = (1u << 18),
    CPU_BASED2_PT_CONCEAL_VMX            = (1u << 19),
    CPU_BASED2_XSAVES_XRSTORS            = (1u << 20),
    CPU_BASED2_EPT_MODE_BASED_EXEC        = (1u << 22),
    CPU_BASED2_EPT_SUBPAGE_WRITE        = (1u << 23),
    CPU_BASED2_PT_GUEST_PHYSICAL        = (1u << 24),
    CPU_BASED2_TSC_SCALING                = (1u << 25),
    CPU_BASED2_USER_WAIT_PAUSE            = (1u << 26),
    CPU_BASED2_ENCLV_EXIT_MAP            = (1u << 28),

    VMX_EPT_VPID_SUPPORT_AD                = (1u << 21),
    VMX_EPT_VPID_ADV_VMEXIT_INFO        = (1u << 22),
    VMX_EPT_VPID_SUPPORT_EXONLY            = (1u << 0),

    // VM-Exit Controls
    VMEXIT_SAVE_DBG_CONTROLS            = (1u << 2),
    VMEXIT_HOST_IA32E                    = (1u << 9),
    VMEXIT_LOAD_IA32_PERF_GLOBAL_CTRL    = (1u << 12),
    VMEXIT_ACK_INTR                        = (1u << 15),
    VMEXIT_SAVE_IA32_PAT                = (1u << 18),
    VMEXIT_LOAD_IA32_PAT                = (1u << 19),
    VMEXIT_SAVE_EFER                    = (1u << 20),
    VMEXIT_LOAD_EFER                    = (1u << 21),
    VMEXIT_SAVE_VMX_TIMER                = (1u << 22),
    VMEXIT_CLEAR_IA32_BNDCFGS            = (1u << 23),
    VMEXIT_PT_CONCEAL_VMX                = (1u << 24),
    VMEXIT_CLEAR_IA32_RTIT_CTL            = (1u << 25),
    VMEXIT_LOAD_CET_STATE                = (1u << 28),
    VMEXIT_LOAD_PKRS                    = (1u << 29),

    // VM-Entry Controls
    VMENTRY_LOAD_DBG_CONTROLS            = (1u << 2),
    VMENTRY_GUEST_IA32E                    = (1u << 9),
    VMENTRY_SMM                            = (1u << 10),
    VMENTRY_DEACTIVATE_DUAL_MONITOR        = (1u << 11),
    VMENTRY_LOAD_IA32_PERF_GLOBAL_CTRL    = (1u << 13),
    VMENTRY_LOAD_IA32_PAT                = (1u << 14),
    VMENTRY_LOAD_EFER                    = (1u << 15),
    VMENTRY_LOAD_IA32_BNDCFGS            = (1u << 16),
    VMENTRY_PT_CONCEAL_VMX                = (1u << 17),
    VMENTRY_LOAD_IA32_RTIT_CTL            = (1u << 18),
    VMENTRY_LOAD_CET_STATE                = (1u << 20),
    VMENTRY_LOAD_PKRS                    = (1u << 22),
};

// VMX Basic Exit Reasons

enum {
    VMX_REASON_EXC_NMI                    = 0,
    VMX_REASON_IRQ                        = 1,
    VMX_REASON_TRIPLE_FAULT                = 2,
    VMX_REASON_INIT                        = 3,
    VMX_REASON_SIPI                        = 4,
    VMX_REASON_IO_SMI                    = 5,
    VMX_REASON_OTHER_SMI                = 6,
    VMX_REASON_IRQ_WND                    = 7,
    VMX_REASON_VIRTUAL_NMI_WND            = 8,
    VMX_REASON_TASK                        = 9,
    VMX_REASON_CPUID                    = 10,
    VMX_REASON_GETSEC                    = 11,
    VMX_REASON_HLT                        = 12,
    VMX_REASON_INVD                        = 13,
    VMX_REASON_INVLPG                    = 14,
    VMX_REASON_RDPMC                    = 15,
    VMX_REASON_RDTSC                    = 16,
    VMX_REASON_RSM                        = 17,
    VMX_REASON_VMCALL                    = 18,
    VMX_REASON_VMCLEAR                    = 19,
    VMX_REASON_VMLAUNCH                    = 20,
    VMX_REASON_VMPTRLD                    = 21,
    VMX_REASON_VMPTRST                    = 22,
    VMX_REASON_VMREAD                    = 23,
    VMX_REASON_VMRESUME                    = 24,
    VMX_REASON_VMWRITE                    = 25,
    VMX_REASON_VMOFF                    = 26,
    VMX_REASON_VMON                        = 27,
    VMX_REASON_MOV_CR                    = 28,
    VMX_REASON_MOV_DR                    = 29,
    VMX_REASON_IO                        = 30,
    VMX_REASON_RDMSR                    = 31,
    VMX_REASON_WRMSR                    = 32,
    VMX_REASON_VMENTRY_GUEST            = 33,
    VMX_REASON_VMENTRY_MSR                = 34,
    VMX_REASON_MWAIT                    = 36,
    VMX_REASON_MTF                        = 37,
    VMX_REASON_MONITOR                    = 39,
    VMX_REASON_PAUSE                    = 40,
    VMX_REASON_VMENTRY_MC                = 41,
    VMX_REASON_TPR_THRESHOLD            = 43,
    VMX_REASON_APIC_ACCESS                = 44,
    VMX_REASON_VIRTUALIZED_EOI            = 45,
    VMX_REASON_GDTR_IDTR                = 46,
    VMX_REASON_LDTR_TR                    = 47,
    VMX_REASON_EPT_VIOLATION            = 48,
    VMX_REASON_EPT_MISCONFIG            = 49,
    VMX_REASON_EPT_INVEPT                = 50,
    VMX_REASON_RDTSCP                    = 51,
    VMX_REASON_VMX_TIMER_EXPIRED        = 52,
    VMX_REASON_INVVPID                    = 53,
    VMX_REASON_WBINVD                    = 54,
    VMX_REASON_XSETBV                    = 55,
    VMX_REASON_APIC_WRITE                = 56,
    VMX_REASON_RDRAND                    = 57,
    VMX_REASON_INVPCID                    = 58,
    VMX_REASON_VMFUNC                    = 59,
    VMX_REASON_ENCLS                    = 60,
    VMX_REASON_RDSEED                    = 61,
    VMX_REASON_PML_FULL                    = 62,
    VMX_REASON_XSAVES                    = 63,
    VMX_REASON_XRSTORS                    = 64,
    VMX_REASON_SPP_EVENT                = 66,
    VMX_REASON_UMWAIT                    = 67,
    VMX_REASON_TPAUSE                    = 68
};

enum {
    HV_MSR_IA32_TSC                         = 0x00000010,

    HV_MSR_IA32_SPEC_CTRL                   = 0x00000048,
    HV_MSR_IA32_PRED_CMD                    = 0x00000049,

    HV_MSR_IA32_PMC0                        = 0x000000c1,
    HV_MSR_IA32_PMC7                        = HV_MSR_IA32_PMC0 + 7,

    HV_MSR_IA32_ARCH_CAPABILITIES           = 0x0000010a,
    HV_MSR_IA32_FLUSH_CMD                   = 0x0000010b,

    HV_MSR_IA32_SYSENTER_CS                 = 0x00000174,
    HV_MSR_IA32_SYSENTER_ESP                = 0x00000175,
    HV_MSR_IA32_SYSENTER_EIP                = 0x00000176,

    HV_MSR_IA32_PERFEVNTSEL0                = 0x00000186,
    HV_MSR_IA32_PERFEVNTSEL7                = HV_MSR_IA32_PERFEVNTSEL0 + 7,

    HV_MSR_LBR_SELECT                       = 0x000001c8,
    HV_MSR_LASTBRANCH_TOS                   = 0x000001c9,

    HV_MSR_LASTINT_FROM_IP                  = 0x000001dd,
    HV_MSR_LASTINT_TO_IP                    = 0x000001de,

    HV_MSR_IA32_DEBUGCTL                    = 0x000001d9,

    HV_MSR_IA32_FIXED_CTR0                  = 0x00000309,
    HV_MSR_IA32_FIXED_CTR1                  = 0x0000030a,
    HV_MSR_IA32_FIXED_CTR2                  = 0x0000030b,
    HV_MSR_IA32_FIXED_CTR3                  = 0x0000030c,    // Table 18-2

    HV_MSR_PERF_METRICS                     = 0x00000329,

    HV_MSR_IA32_FIXED_CTR_CTRL              = 0x0000038d,

    HV_MSR_IA32_PERF_GLOBAL_STATUS          = 0x0000038e,
    HV_MSR_IA32_PERF_GLOBAL_CTRL            = 0x0000038f,
    HV_MSR_IA32_PERF_GLOBAL_STATUS_RESET    = 0x00000390,
    HV_MSR_IA32_PERF_GLOBAL_STATUS_SET      = 0x00000391,
    HV_MSR_IA32_PERF_GLOBAL_INUSE           = 0x00000392,

    HV_MSR_IA32_A_PMC0                      = 0x000004c1,
    HV_MSR_IA32_A_PMC7                      = HV_MSR_IA32_A_PMC0 + 7,

    HV_MSR_LASTBRANCH_0_FROM_IP             = 0x00000680,
    HV_MSR_LASTBRANCH_31_FROM_IP            = HV_MSR_LASTBRANCH_0_FROM_IP + 31,

    HV_MSR_LASTBRANCH_0_TO_IP               = 0x000006c0,
    HV_MSR_LASTBRANCH_31_TO_IP              = HV_MSR_LASTBRANCH_0_TO_IP + 31,

    HV_MSR_IA32_XSS                         = 0x00000da0,

    HV_MSR_LASTBRANCH_INFO_0                = 0x00000dc0,
    HV_MSR_LASTBRANCH_INFO_31               = HV_MSR_LASTBRANCH_INFO_0 + 31,

    HV_MSR_IA32_EFER                        = 0xc0000080,
    HV_MSR_IA32_STAR                        = 0xc0000081,
    HV_MSR_IA32_LSTAR                       = 0xc0000082,
    HV_MSR_IA32_CSTAR                       = 0xc0000083,
    HV_MSR_IA32_FMASK                       = 0xc0000084,
    HV_MSR_IA32_FS_BASE                     = 0xc0000100,
    HV_MSR_IA32_GS_BASE                     = 0xc0000101,
    HV_MSR_IA32_KERNEL_GS_BASE              = 0xc0000102,
    HV_MSR_IA32_TSC_AUX                     = 0xc0000103,
};

// See: "Format of the IDT-Vectoring Information Field"

enum {
    IRQ_INFO_EXT_IRQ                    = (0u << 8),
    IRQ_INFO_VECTOR_MASK                = ((1u << 8) - 1),
    IRQ_INFO_NMI                        = (2u << 8),
    IRQ_INFO_HARD_EXC                    = (3u << 8),
    IRQ_INFO_SOFT_IRQ                    = (4u << 8),
    IRQ_INFO_PRIV_SOFT_EXC                = (5u << 8),
    IRQ_INFO_SOFT_EXC                    = (6u << 8),
    IRQ_INFO_TYPE_MASK                    = (7u << 8),

    IRQ_INFO_ERROR_VALID                = (1u << 11),
    IRQ_INFO_VALID                        = (1u << 31)
};

#define GUEST_INTRBILITY_STI_BLOCKING    (1ull << 0)
#define GUEST_INTRBILITY_MOVSS_BLOCKING    (1ull << 1)
#define GUEST_INTRBILITY_SMI_BLOCKING    (1ull << 2)
#define GUEST_INTRBILITY_NMI_BLOCKING    (1ull << 3)

__END_DECLS

OS_ASSUME_NONNULL_END

#endif    /* ifndef __ASSEMBLER__ */

#endif /* __x86_64__ */

#endif /* __HYPERVISOR_HV_ARCH_VMX__ */
