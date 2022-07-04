// https://iconarchive.com/show/farm-fresh-icons-by-fatcow/temperature-5-icon.html
// https://www.flaticon.com/search?word=bluetooth&order_by=4&type=icon

// 'wifi-icon', 16x16px
const unsigned char iconWiFi [32] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xc0, 0x03, 0x8f, 0xf1, 0x1f, 0xf8, 0xb8, 0x1d, 0xe1, 0x87, 
	0xe7, 0xe7, 0xfc, 0x3f, 0xf8, 0x1f, 0xfb, 0xdf, 0xfe, 0x7f, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff
};
// 'wifi-icon-med', 16x16px
const unsigned char iconWiFiMed [32] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xe1, 0x87, 
	0xe7, 0xe7, 0xfc, 0x3f, 0xf8, 0x1f, 0xff, 0xff, 0xfe, 0x7f, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff
};
// 'wifi-icon-low', 16x16px
const unsigned char iconWiFiLow [32] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xfc, 0x3f, 0xf8, 0x1f, 0xff, 0xff, 0xfe, 0x7f, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff
};
// 'wifi-icon-empty', 16x16px
const unsigned char iconWiFiEmpty [32] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff
};
// 'iconMQTT', 16x16px
const unsigned char iconMQTT[32] PROGMEM = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xc3, 0xe1,0xc3, 0xe1, 0x83, 0xe1, 0x83,
	0xe0, 0x83, 0xe4, 0x83, 0xe4, 0x03, 0xe4, 0x23, 0xe4, 0x23, 0xe6, 0x23, 0xe6, 0x73, 0xff, 0xff
};
// 'iconHumidity', 16x16px
const uint16_t iconHumidity[256] PROGMEM = {
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc79f, 0xc79f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xbf7f, 0xc79f, 0xc79f, 0xf7ff, 0xcf9f, 0xc7bf, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc79f, 0xc79f, 0xc79f, 0xcf9f, 0xcf9f, 0xc79f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xefdf, 0xdfbf, 0xc79f, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0xffff, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xcfbf, 0xf7ff, 0xc79f, 0xffff, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0xbf9f, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xefdf, 0xdfbf, 0xc79f, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0xbf7f, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xd7bf, 0xf7ff, 0xc79f, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0xb77f, 0xb77f, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xc79f, 0xe7df, 0xc79f, 0xc79f, 0x0000, 0x0000, 
	0x0000, 0x0000, 0xb77f, 0x9f3f, 0x86bd, 0x86bd, 0x8ede, 0x8ede, 0x86bd, 0x86bd, 0x86bd, 0x86bd, 0xb77f, 0xc79f, 0x0000, 0x0000, 
	0x0000, 0x0000, 0xb75f, 0x86bd, 0x4dfb, 0x5e5c, 0xbf5e, 0xbf5e, 0x7e9d, 0xa71e, 0x5e5c, 0x5e5c, 0xa73e, 0xc79f, 0x0000, 0x0000, 
	0x0000, 0x0000, 0xb77f, 0x9f1f, 0x2d59, 0x563c, 0x6e7d, 0x86bd, 0xb73e, 0x5e5c, 0x5e5c, 0x5e5c, 0xb75f, 0xb77f, 0x0000, 0x0000, 
	0x0000, 0x0000, 0xb77f, 0xa75f, 0x3d9a, 0x2d39, 0x6e3c, 0xb73e, 0x9efe, 0x9efe, 0x5e5c, 0x665c, 0xaf5f, 0xbf5f, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0xaf7f, 0xa75f, 0x3d9a, 0x5dfa, 0x2d39, 0x7e7c, 0x7e5c, 0x3d9a, 0xa75f, 0xaf7f, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0xaf7f, 0xa75f, 0x8ede, 0x663c, 0x5e3c, 0x86bd, 0xa75f, 0xaf7f, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xb77f, 0xaf5f, 0xaf5f, 0xaf7f, 0xaf7f, 0xb75f, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};
// 'iconTemperature', 16x16px
const uint16_t iconTemperature[256] PROGMEM = {
	0x0000, 0x0000, 0x0000, 0x0000, 0xf7df, 0xf7df, 0xe7df, 0xe7bf, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0xf7df, 0xef9f, 0xcefc, 0xdfbf, 0xe7bf, 0x0000, 0x6c32, 0x6c52, 0x6c52, 0x6453, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0xf7df, 0xcedc, 0x8536, 0xe7bf, 0xe7bf, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0xf7df, 0xc6dc, 0x8536, 0xe7bf, 0xe7bf, 0x0000, 0x6c32, 0x6452, 0x6472, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0xf7df, 0xc6dc, 0x8536, 0xe7bf, 0xe7bf, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0xf7df, 0xe452, 0xf1a9, 0xe7bf, 0xe7bf, 0x0000, 0x6473, 0x6c52, 0x6c52, 0x6453, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0xf7df, 0xe3d0, 0xf967, 0xe7bf, 0xe7bf, 0x0000, 0x07ff, 0x6c32, 0x5415, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0xf7df, 0xe3d0, 0xf967, 0xe7bf, 0xe7bf, 0x0000, 0x6c32, 0x6c72, 0x6452, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0xf7df, 0xe3d0, 0xf967, 0xe7bf, 0xe7bf, 0x0000, 0x8410, 0x6c32, 0x6c32, 0x07ff, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0xffff, 0xf7df, 0xe3d0, 0xf967, 0xe7bf, 0xe7bf, 0x0000, 0x6c32, 0x6c72, 0x6c72, 0x6cb2, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0xf7df, 0xef9f, 0xe32e, 0xf967, 0xe493, 0xdfbf, 0xe7bf, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0xf7ff, 0xf7df, 0xdc11, 0xfa4a, 0xfa09, 0xf947, 0xe5b8, 0xe7bf, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0xefdf, 0xf7df, 0xe30d, 0xfa4a, 0xfa4a, 0xf947, 0xe3d1, 0xdfbf, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0xe7ff, 0xf7df, 0xdc93, 0xfa4a, 0xfa09, 0xf967, 0xe65a, 0xe7bf, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0xf7df, 0xf7df, 0xdd36, 0xe30e, 0xe5f8, 0xdfbf, 0xe7bf, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0xffff, 0xf7df, 0xf7df, 0xefdf, 0xe7bf, 0xe7bf, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};