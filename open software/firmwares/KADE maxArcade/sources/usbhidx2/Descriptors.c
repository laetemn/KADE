/*
             LUFA Library
     Copyright (C) Dean Camera, 2011.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2011  Dean Camera (dean [at] fourwalledcubicle [dot] com)
  Copyright 2010  Denver Gingerich (denver [at] ossguy [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  USB Device Descriptors, for library use when in USB device mode. Descriptors are special
 *  computer-readable structures which the host requests upon device enumeration, to determine
 *  the device's capabilities and functions.
 */

#include "Descriptors.h"

#if (USE_INTERNAL_SERIAL == NO_DESCRIPTOR)
    #warning USE_INTERNAL_SERIAL is not available on this AVR - please manually construct a device serial descriptor.
#endif

/** HID class report descriptor. This is a special descriptor constructed with values from the
 *  USBIF HID class specification to describe the reports and capabilities of the HID device. This
 *  descriptor is parsed by the host and its contents used to determine what data (and in what encoding)
 *  the device will send, and what it may be sent back from the host. Refer to the HID specification for
 *  more details on HID report descriptors.
 *
 *  This descriptor describes the multiple possible reports of the HID interface's report structure.
 */
const USB_Descriptor_HIDReport_Datatype_t PROGMEM HIDReport[] =
{

	/* Joystick Report */
	HID_RI_USAGE_PAGE(8, 0x01), /* Generic Desktop */
	HID_RI_USAGE(8, 0x04), /* Joystick */
	HID_RI_COLLECTION(8, 0x01), /* Application */
		HID_RI_REPORT_ID(8, HID_REPORTID_JoystickReport),
	    HID_RI_USAGE(8, 0x01), /* Pointer */
	    HID_RI_COLLECTION(8, 0x00), /* Physical */
	        HID_RI_USAGE(8, 0x30), /* Usage X */
	        HID_RI_USAGE(8, 0x31), /* Usage Y */
	        HID_RI_USAGE(8, 0x32), /* Usage X */  //JW added - can add more as 34, 35 etc
	        HID_RI_USAGE(8, 0x33), /* Usage Y */
	        HID_RI_LOGICAL_MINIMUM(8, -128),
	        HID_RI_LOGICAL_MAXIMUM(8, 127),
	        HID_RI_PHYSICAL_MINIMUM(8, -1),
	        HID_RI_PHYSICAL_MAXIMUM(8, 1),
	        //HID_RI_REPORT_COUNT(8, 0x02),  //increase axis from 2 to 4
	        HID_RI_REPORT_COUNT(8, 0x04),
	        HID_RI_REPORT_SIZE(8, 0x08),
	        HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),
	    HID_RI_END_COLLECTION(0),
		
		//Hat Switch Start (Working)
		HID_RI_USAGE_PAGE(8, 0x01), // Generic Desktop
        0x09, 0x39,             //     USAGE (Hat switch)
        0x95, 0x01,             //     REPORT_COUNT (1)
        0x75, 0x04,             //     REPORT_SIZE (4)
        0x15, 0x00,             //     LOGICAL_MINIMUM (0)
        0x25, 0x07,             //     LOGICAL_MAXIMUM (7)
        0x46, 0x3B, 0x01,       //     PHYSICAL_MAXIMUM (315)
        0x65, 0x14,             //     UNIT (Eng Rot:Angular Pos)
        0x81, 0x42,             //     INPUT (Data,Var,Abs,Null)         4b Hat
        0x75, 0x04,             //     REPORT_SIZE (4)
        0x95, 0x01,             //     REPORT_COUNT (1)
        0x81, 0x01,             //     INPUT (Cnst,Ary,Abs)              4b Fill 
        0x55, 0x00,     // ( UNIT_EXPONENT ( 0))
        0x65, 0x00,     // ( UNIT ( None))
		//Hat Switch End
				
		
	    HID_RI_USAGE_PAGE(8, 0x09), /* Button */
	    HID_RI_USAGE_MINIMUM(8, 0x01),
	    HID_RI_USAGE_MAXIMUM(8, 0x10),  //16 buttons (can increase in factors of 8)
	    HID_RI_LOGICAL_MINIMUM(8, 0x00),
	    HID_RI_LOGICAL_MAXIMUM(8, 0x01),
	    HID_RI_REPORT_SIZE(8, 0x01),
	    HID_RI_REPORT_COUNT(8, 0x10),   //16 buttons (can increase in factors of 8)
	    HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),
	    //HID_RI_REPORT_SIZE(8, 0x06),
	    //HID_RI_REPORT_COUNT(8, 0x01),
	    HID_RI_INPUT(8, HID_IOF_CONSTANT),
	HID_RI_END_COLLECTION(0),
	
	
	/* Keyboard Report */
	HID_RI_USAGE_PAGE(8, 0x01), /* Generic Desktop */
	HID_RI_USAGE(8, 0x06), /* Keyboard */
	HID_RI_COLLECTION(8, 0x01), /* Application */
		HID_RI_REPORT_ID(8, HID_REPORTID_KeyboardReport),
	    HID_RI_USAGE_PAGE(8, 0x07), /* Key Codes */
	    HID_RI_USAGE_MINIMUM(8, 0xE0), /* Keyboard Left Control */
	    HID_RI_USAGE_MAXIMUM(8, 0xE7), /* Keyboard Right GUI */
	    HID_RI_LOGICAL_MINIMUM(8, 0x00),
	    HID_RI_LOGICAL_MAXIMUM(8, 0x01),
	    HID_RI_REPORT_SIZE(8, 0x01),
	    HID_RI_REPORT_COUNT(8, 0x08),
	    HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),
	    HID_RI_REPORT_COUNT(8, 0x01),
	    HID_RI_REPORT_SIZE(8, 0x08),
	    HID_RI_INPUT(8, HID_IOF_CONSTANT),
	    HID_RI_USAGE_PAGE(8, 0x08), /* LEDs */
	    HID_RI_USAGE_MINIMUM(8, 0x01), /* Num Lock */
	    HID_RI_USAGE_MAXIMUM(8, 0x05), /* Kana */
	    HID_RI_REPORT_COUNT(8, 0x05),
	    HID_RI_REPORT_SIZE(8, 0x01),
	    HID_RI_OUTPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE | HID_IOF_NON_VOLATILE),
	    HID_RI_REPORT_COUNT(8, 0x01),
	    HID_RI_REPORT_SIZE(8, 0x03),
	    HID_RI_OUTPUT(8, HID_IOF_CONSTANT),
	    HID_RI_LOGICAL_MINIMUM(8, 0x00),
	    HID_RI_LOGICAL_MAXIMUM(8, 0xff),
	    HID_RI_USAGE_PAGE(8, 0x07), /* Keyboard */
	    HID_RI_USAGE_MINIMUM(8, 0x00), /* Reserved (no event indicated) */
	    HID_RI_USAGE_MAXIMUM(8, 0xff), /* Keyboard Application */
	    HID_RI_REPORT_COUNT(8, 0x0f),
	    HID_RI_REPORT_SIZE(8, 0x08),
	    HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_ARRAY | HID_IOF_ABSOLUTE),
	HID_RI_END_COLLECTION(0),

	/* Joystick Report */
	HID_RI_USAGE_PAGE(8, 0x01), /* Generic Desktop */
	HID_RI_USAGE(8, 0x04), /* Joystick */
	HID_RI_COLLECTION(8, 0x01), /* Application */
		HID_RI_REPORT_ID(8, HID_REPORTID_JoystickReport2),
	    HID_RI_USAGE(8, 0x01), /* Pointer */
	    HID_RI_COLLECTION(8, 0x00), /* Physical */
	        HID_RI_USAGE(8, 0x30), /* Usage X */
	        HID_RI_USAGE(8, 0x31), /* Usage Y */
	        HID_RI_USAGE(8, 0x32), /* Usage X */  //JW added - can add more as 34, 35 etc
	        HID_RI_USAGE(8, 0x33), /* Usage Y */
	        HID_RI_LOGICAL_MINIMUM(8, -128),
	        HID_RI_LOGICAL_MAXIMUM(8, 127),
	        HID_RI_PHYSICAL_MINIMUM(8, -1),
	        HID_RI_PHYSICAL_MAXIMUM(8, 1),
	        //HID_RI_REPORT_COUNT(8, 0x02),  //increase axis from 2 to 4
	        HID_RI_REPORT_COUNT(8, 0x04),
	        HID_RI_REPORT_SIZE(8, 0x08),
	        HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),
	    HID_RI_END_COLLECTION(0),
		
		//Hat Switch Start (Working)
		HID_RI_USAGE_PAGE(8, 0x01), // Generic Desktop
        0x09, 0x39,             //     USAGE (Hat switch)
        0x95, 0x01,             //     REPORT_COUNT (1)
        0x75, 0x04,             //     REPORT_SIZE (4)
        0x15, 0x00,             //     LOGICAL_MINIMUM (0)
        0x25, 0x07,             //     LOGICAL_MAXIMUM (7)
        0x46, 0x3B, 0x01,       //     PHYSICAL_MAXIMUM (315)
        0x65, 0x14,             //     UNIT (Eng Rot:Angular Pos)
        0x81, 0x42,             //     INPUT (Data,Var,Abs,Null)         4b Hat
        0x75, 0x04,             //     REPORT_SIZE (4)
        0x95, 0x01,             //     REPORT_COUNT (1)
        0x81, 0x01,             //     INPUT (Cnst,Ary,Abs)              4b Fill 
        0x55, 0x00,  			// ( UNIT_EXPONENT ( 0))
        0x65, 0x00,				// ( UNIT ( None))
		//Hat Switch End				
		
	    HID_RI_USAGE_PAGE(8, 0x09), /* Button */
	    HID_RI_USAGE_MINIMUM(8, 0x01),
	    HID_RI_USAGE_MAXIMUM(8, 0x10),  //16 buttons (can increase in factors of 8)
	    HID_RI_LOGICAL_MINIMUM(8, 0x00),
	    HID_RI_LOGICAL_MAXIMUM(8, 0x01),
	    HID_RI_REPORT_SIZE(8, 0x01),
	    HID_RI_REPORT_COUNT(8, 0x10),   //16 buttons (can increase in factors of 8)
	    HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),
	    //HID_RI_REPORT_SIZE(8, 0x06),
	    //HID_RI_REPORT_COUNT(8, 0x01),
	    HID_RI_INPUT(8, HID_IOF_CONSTANT),
	HID_RI_END_COLLECTION(0),
};

/** Device descriptor structure. This descriptor, located in FLASH memory, describes the overall
 *  device characteristics, including the supported USB version, control endpoint size and the
 *  number of device configurations. The descriptor is read out by the USB host when the enumeration
 *  process begins.
 */
const USB_Descriptor_Device_t PROGMEM DeviceDescriptor =
{
    .Header                 = {.Size = sizeof(USB_Descriptor_Device_t), .Type = DTYPE_Device},

    .USBSpecification       = VERSION_BCD(01.10),
    .Class                  = USB_CSCP_NoDeviceClass,
    .SubClass               = USB_CSCP_NoDeviceSubclass,
    .Protocol               = USB_CSCP_NoDeviceProtocol,

    .Endpoint0Size          = FIXED_CONTROL_ENDPOINT_SIZE,

    .VendorID               = 0x03EB,
    .ProductID              = 0x204E,
    .ReleaseNumber          = VERSION_BCD(00.01),

    .ManufacturerStrIndex   = 0x01,
    .ProductStrIndex        = 0x02,
    .SerialNumStrIndex      = USE_INTERNAL_SERIAL,

    .NumberOfConfigurations = FIXED_NUM_CONFIGURATIONS
};

/** Configuration descriptor structure. This descriptor, located in FLASH memory, describes the usage
 *  of the device in one of its supported configurations, including information about any device interfaces
 *  and endpoints. The descriptor is read out by the USB host during the enumeration process when selecting
 *  a configuration so that the host may correctly communicate with the USB device.
 */
const USB_Descriptor_Configuration_t PROGMEM ConfigurationDescriptor =
{
    .Config =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Configuration_Header_t), .Type = DTYPE_Configuration},

            .TotalConfigurationSize = sizeof(USB_Descriptor_Configuration_t),
            .TotalInterfaces        = 3,

            .ConfigurationNumber    = 1,
            .ConfigurationStrIndex  = 0x02,

            .ConfigAttributes       = (USB_CONFIG_ATTR_BUSPOWERED | USB_CONFIG_ATTR_SELFPOWERED),

            .MaxPowerConsumption    = USB_CONFIG_POWER_MA(100)
        },

    .CDC_IAD =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Interface_Association_t), .Type = DTYPE_InterfaceAssociation},

            .FirstInterfaceIndex    = 0,
            .TotalInterfaces        = 2,

            .Class                  = CDC_CSCP_CDCClass,
            .SubClass               = CDC_CSCP_ACMSubclass,
            .Protocol               = CDC_CSCP_ATCommandProtocol,

            .IADStrIndex            = 0x02
        },

    .CDC_CCI_Interface =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},

            .InterfaceNumber        = 0x00,
            .AlternateSetting       = 0x00,

            .TotalEndpoints         = 1,

            .Class                  = CDC_CSCP_CDCClass,
            .SubClass               = CDC_CSCP_ACMSubclass,
            .Protocol               = CDC_CSCP_ATCommandProtocol,

            .InterfaceStrIndex      = 0x03
        },

    .CDC_Functional_Header =
        {
            .Header                 = {.Size = sizeof(USB_CDC_Descriptor_FunctionalHeader_t), .Type = DTYPE_CSInterface},
            .Subtype                = CDC_DSUBTYPE_CSInterface_Header,

            .CDCSpecification       = VERSION_BCD(01.10),
        },

    .CDC_Functional_ACM =
        {
            .Header                 = {.Size = sizeof(USB_CDC_Descriptor_FunctionalACM_t), .Type = DTYPE_CSInterface},
            .Subtype                = CDC_DSUBTYPE_CSInterface_ACM,

            .Capabilities           = 0x06,
        },

    .CDC_Functional_Union =
        {
            .Header                 = {.Size = sizeof(USB_CDC_Descriptor_FunctionalUnion_t), .Type = DTYPE_CSInterface},
            .Subtype                = CDC_DSUBTYPE_CSInterface_Union,

            .MasterInterfaceNumber  = 0,
            .SlaveInterfaceNumber   = 1,
        },

    .CDC_NotificationEndpoint =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

            .EndpointAddress        = (ENDPOINT_DIR_IN | CDC_NOTIFICATION_EPNUM),
            .Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
            .EndpointSize           = CDC_NOTIFICATION_EPSIZE,
            .PollingIntervalMS      = 0xFF
        },

    .CDC_DCI_Interface =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},

            .InterfaceNumber        = 0x01,
            .AlternateSetting       = 0x00,

            .TotalEndpoints         = 2,

            .Class                  = CDC_CSCP_CDCDataClass,
            .SubClass               = CDC_CSCP_NoDataSubclass,
            .Protocol               = CDC_CSCP_NoDataProtocol,

            .InterfaceStrIndex      = 0x03
        },

    .CDC_DataOutEndpoint =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

            .EndpointAddress        = (ENDPOINT_DIR_OUT | CDC_RX_EPNUM),
            .Attributes             = (EP_TYPE_BULK | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
            .EndpointSize           = CDC_TXRX_EPSIZE,
            .PollingIntervalMS      = 0x01
        },

    .CDC_DataInEndpoint =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

            .EndpointAddress        = (ENDPOINT_DIR_IN | CDC_TX_EPNUM),
            .Attributes             = (EP_TYPE_BULK | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
            .EndpointSize           = CDC_TXRX_EPSIZE,
            .PollingIntervalMS      = 0x01
        },

    .HID_Interface =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface},

            .InterfaceNumber        = 0x02,
            .AlternateSetting       = 0x00,

            .TotalEndpoints         = 2,

            .Class                  = HID_CSCP_HIDClass,
//          .SubClass               = HID_CSCP_NonBootSubclass,
// 			.Protocol               = HID_CSCP_NonBootProtocol, 
            .SubClass               = HID_CSCP_BootSubclass,
            .Protocol               = HID_CSCP_KeyboardBootProtocol,

            .InterfaceStrIndex      = 0x04
        },

    .HID_GenericHID =
        {
            .Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID},

            .HIDSpec                = VERSION_BCD(01.11),
            .CountryCode            = 0x00,
            .TotalReportDescriptors = 1,
            .HIDReportType          = HID_DTYPE_Report,
            .HIDReportLength        = sizeof(HIDReport)
        },

    .HID_ReportINEndpoint =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

            .EndpointAddress        = (ENDPOINT_DIR_IN | GENERIC_IN_EPNUM),
            .Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
            .EndpointSize           = GENERIC_EPSIZE,
            .PollingIntervalMS      = 0x01
        },

    .HID_ReportOUTEndpoint =
        {
            .Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint},

            .EndpointAddress        = (ENDPOINT_DIR_OUT | GENERIC_OUT_EPNUM),
            .Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA),
            .EndpointSize           = GENERIC_EPSIZE,
            .PollingIntervalMS      = 0x01
        }

};

/** Language descriptor structure. This descriptor, located in FLASH memory, is returned when the host requests
 *  the string descriptor with index 0 (the first index). It is actually an array of 16-bit integers, which indicate
 *  via the language ID table available at USB.org what languages the device supports for its string descriptors.
 */
const USB_Descriptor_String_t PROGMEM LanguageString =
{
    .Header                 = {.Size = USB_STRING_LEN(1), .Type = DTYPE_String},

    .UnicodeString          = {LANGUAGE_ID_ENG}
};

/** Manufacturer descriptor string. This is a Unicode string containing the manufacturer's details in human readable
 *  form, and is read out upon request by the host when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t PROGMEM ManufacturerString =
{
    .Header                 = {.Size = USB_STRING_LEN(4), .Type = DTYPE_String},

    .UnicodeString          = L"KADE"
};

/** Product descriptor string. This is a Unicode string containing the product's details in human readable form,
 *  and is read out upon request by the host when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t PROGMEM ProductString =
{
    .Header                 = {.Size = USB_STRING_LEN(14), .Type = DTYPE_String},

    .UnicodeString          = L"KADE fatArcade"
};

/** Product descriptor string. This is a Unicode string containing the product's details in human readable form,
 *  and is read out upon request by the host when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t PROGMEM ProductStringSerial =
{
    .Header                 = {.Size = USB_STRING_LEN(14), .Type = DTYPE_String},

    .UnicodeString          = L"KADE fatArcade"
};

/** Product descriptor string. This is a Unicode string containing the product's details in human readable form,
 *  and is read out upon request by the host when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t PROGMEM ProductStringHID =
{
    .Header                 = {.Size = USB_STRING_LEN(14), .Type = DTYPE_String},

    .UnicodeString          = L"KADE fatArcade"
};

/** This function is called by the library when in device mode, and must be overridden (see library "USB Descriptors"
 *  documentation) by the application code so that the address and size of a requested descriptor can be given
 *  to the USB library. When the device receives a Get Descriptor request on the control endpoint, this function
 *  is called so that the descriptor details can be passed back and the appropriate descriptor sent back to the
 *  USB host.
 */
uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
                                    const uint8_t wIndex,
                                    const void** const DescriptorAddress)
{
    const uint8_t  DescriptorType   = (wValue >> 8);
    const uint8_t  DescriptorNumber = (wValue & 0xFF);

    const void* Address = NULL;
    uint16_t    Size    = NO_DESCRIPTOR;

    switch (DescriptorType)
    {
        case DTYPE_Device:
            Address = &DeviceDescriptor;
            Size    = sizeof(USB_Descriptor_Device_t);
            break;
        case DTYPE_Configuration:
            Address = &ConfigurationDescriptor;
            Size    = sizeof(USB_Descriptor_Configuration_t);
            break;
        case DTYPE_String:
            switch (DescriptorNumber)
            {
                case 0x00:
                    Address = &LanguageString;
                    Size    = pgm_read_byte(&LanguageString.Header.Size);
                    break;
                case 0x01:
                    Address = &ManufacturerString;
                    Size    = pgm_read_byte(&ManufacturerString.Header.Size);
                    break;
                case 0x02:
                    Address = &ProductString;
                    Size    = pgm_read_byte(&ProductString.Header.Size);
                    break;
                case 0x03:
                    Address = &ProductStringSerial;
                    Size    = pgm_read_byte(&ProductStringSerial.Header.Size);
                    break;
                case 0x04:
                    Address = &ProductStringHID;
                    Size    = pgm_read_byte(&ProductStringHID.Header.Size);
                    break;
            }

            break;
        case HID_DTYPE_HID:
            Address = &ConfigurationDescriptor.HID_GenericHID;
            Size    = sizeof(USB_HID_Descriptor_HID_t);
            break;
        case HID_DTYPE_Report:
            Address = &HIDReport;
            Size    = sizeof(HIDReport);
            break;
    }

    *DescriptorAddress = Address;
    return Size;
}

