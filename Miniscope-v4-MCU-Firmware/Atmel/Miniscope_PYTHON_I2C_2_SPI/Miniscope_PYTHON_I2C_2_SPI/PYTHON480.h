/*
 * PYTHON480.h
 *
 * Created: 7/21/2018 7:51:30 PM
 *  Author: DBAharoni
 */ 


#ifndef PYTHON480_H_
#define PYTHON480_H_

#define DISABLE_PLL

#include "SPI_BB_PYTHON480.h"

void EnableClockMngmnt1() {
// configure clock management blocks, activate clock generation and distribution circuits

spi_BB_Write(2, 0x0000);// Monochrome sensor
spi_BB_Write(17, 0x2113);// Configure PLL
spi_BB_Write(20, 0x0000);// Configure clock management
spi_BB_Write(26, 0x2280);// Configure PLL lock detector
spi_BB_Write(27, 0x3D2D);// Configure PLL lock detector
#ifdef DISABLE_PLL 
	spi_BB_Write(32, 0x7014|0x0008);// spi_BB_Write(32, 0x2004);PLL input clock
#else
	spi_BB_Write(32, 0x7014);// spi_BB_Write(32, 0x2004);PLL input clock
#endif
spi_BB_Write(8, 0x0000);// Release PLL soft reset
#ifdef DISABLE_PLL 
	spi_BB_Write(16,0x0007);// Disable PLL
#else
	spi_BB_Write(16, 0x0003);// Enable PLL Andres says to make this 0x0007. I originally had it at 0x0004. Try 0x0003
#endif
}

void EnableClockMngmnt2() {// Enable internal clock distribution

spi_BB_Write(9, 0x0000);// Release clock generator Soft Reset

//Why is it 0x7006 instead of 0x2006??
#ifdef DISABLE_PLL
	spi_BB_Write(32, 0x7006|0x0008);// spi_BB_Write(32, 0x7006); Enable logic clock. Changed this to 7006 to try
#else
	spi_BB_Write(32, 0x7006);// spi_BB_Write(32, 0x7006); Enable logic clock. Changed this to 7006 to try
#endif

spi_BB_Write(34, 0x0001);// Enable logic blocks
}

void RequiredUploads() {// Reserved register settings uploads

spi_BB_Write(2, 0x0000);
spi_BB_Write(8, 0x0000);
spi_BB_Write(9, 0x0000);
spi_BB_Write(10, 0x0000);
spi_BB_Write(20, 0x0000);
//spi_BB_Write(24, 0x0001);
spi_BB_Write(26, 0x2280);
spi_BB_Write(27, 0x3D2D);
#ifdef DISABLE_PLL
	spi_BB_Write(32, 0x7007|0x0008);
#else
	spi_BB_Write(32, 0x7007);
#endif
spi_BB_Write(34, 0x0001);
spi_BB_Write(40, 0x0007); // 3rd bit endables bias. This was set to 0 (0x003).
spi_BB_Write(41, 0x085F);
spi_BB_Write(42, 0x4103);
spi_BB_Write(43, 0x0518);
spi_BB_Write(48, 0x0001);
spi_BB_Write(64, 0x0001);
spi_BB_Write(65, 0x382A); //Bias block. spi_BB_Write(65, 0x382B)
spi_BB_Write(66, 0x53C8);
spi_BB_Write(67, 0x0665);
spi_BB_Write(68, 0x0085);
spi_BB_Write(69, 0x0888);
spi_BB_Write(70, 0x4800);
spi_BB_Write(71, 0x8888);
spi_BB_Write(72, 0x0117);
//spi_BB_Write(112, 0x0007);
spi_BB_Write(112, 0x0000); // LVDS powerdown config
spi_BB_Write(128, 0x470A); //spi_BB_Write(128, 0x470A); spi_BB_Write(128, 0x4714); black offset
spi_BB_Write(129, 0x8001);
//spi_BB_Write(130, 0x0001); // Handles phase of pixel clock changed from 0x0001 to 0x0015

// Test Pattern
//spi_BB_Write(144,0x0003);

spi_BB_Write(130, 0x0015);
spi_BB_Write(192, 0x0801); // Monitor select function
spi_BB_Write(194, 0x00E4);	// reverse x and y enabled for demo kit compatibility
spi_BB_Write(197, 0x0104); // 0x0380) Num black lines spi_BB_Write(197, 0x030A);
#ifdef DISABLE_PLL 
	spi_BB_Write(199, 167); // Exposure/Frame rate config, spi_BB_Write(199, 0x0299);
	spi_BB_Write(200, 3300); // Frame length, spi_BB_Write(200, 0x0350);
	spi_BB_Write(201, 3300); // spi_BB_Write(201, 2900); // Exposure time spi_BB_Write(201, 0x01F4);
#else
	spi_BB_Write(199, 666); // Exposure/Frame rate config, spi_BB_Write(199, 0x0299);
	spi_BB_Write(200, 3000); // Frame length, spi_BB_Write(200, 0x0350);
	spi_BB_Write(201, 2900); // spi_BB_Write(201, 2900); // Exposure time spi_BB_Write(201, 0x01F4);
#endif
spi_BB_Write(204, 0x00E4); 	// (gain 1x : 0x00E1 // gain 2x : 0x00E4 // gain 3.5x : 0x0024)
spi_BB_Write(207, 0x0014);
spi_BB_Write(214, 0x0100);
spi_BB_Write(215, 0x101F);
spi_BB_Write(216, 0x0000);
spi_BB_Write(219, 0x0023);
spi_BB_Write(220, 0x3C2B);
spi_BB_Write(221, 0x2B4D);
spi_BB_Write(224, 0x3E5E);
spi_BB_Write(211, 0x0049);
spi_BB_Write(216, 0x0000);
spi_BB_Write(219, 0x0023);
spi_BB_Write(220, 0x3C2B);
spi_BB_Write(221, 0x2B4D);
spi_BB_Write(230, 0x0299);
spi_BB_Write(231, 0x0350);
spi_BB_Write(232, 0x01F4);
spi_BB_Write(235, 0x00E1);

// Set ROI Size
spi_BB_Write(256, 0xB019); // Horizontal pixel range times 4 plus 4 for ROI0
spi_BB_Write(258, 0xB019); // Horizontal pixel range times 4 plus 4 for ROI1

//////////////////////////////////////////
////// PROGRAM SPACE //////
//////////////////////////////////////////
spi_BB_Write(384, 0xC800);
spi_BB_Write(385, 0xFB1F);
spi_BB_Write(386, 0xFB1F);
spi_BB_Write(387, 0xFB12);
spi_BB_Write(388, 0xF912);
spi_BB_Write(389, 0xF903);
spi_BB_Write(390, 0xF802);
spi_BB_Write(391, 0xF30F);
spi_BB_Write(392, 0xF30F);
spi_BB_Write(393, 0xF30F);
spi_BB_Write(394, 0xF30A);
spi_BB_Write(395, 0xF101);
spi_BB_Write(396, 0xF00A);
spi_BB_Write(397, 0xF24B);
spi_BB_Write(398, 0xF201);
spi_BB_Write(399, 0xF226);
spi_BB_Write(400, 0xF021);
spi_BB_Write(401, 0xF001);
spi_BB_Write(402, 0xF402);
spi_BB_Write(403, 0xF007);
spi_BB_Write(404, 0xF20F);
spi_BB_Write(405, 0xF20F);
spi_BB_Write(406, 0xF202);
spi_BB_Write(407, 0xF006);
spi_BB_Write(408, 0xEC08);
spi_BB_Write(409, 0xC801);
spi_BB_Write(410, 0xC800);

spi_BB_Write(419, 0xC800);
spi_BB_Write(420, 0xCC02);
spi_BB_Write(421, 0xCC01);
spi_BB_Write(422, 0xCC02);
spi_BB_Write(423, 0xCC01);
spi_BB_Write(424, 0xCC02);
spi_BB_Write(425, 0xC805);
spi_BB_Write(426, 0xC800);

spi_BB_Write(427, 0x0030);
spi_BB_Write(428, 0x207B);
spi_BB_Write(429, 0x2071);
spi_BB_Write(430, 0x0071);
spi_BB_Write(431, 0x107F);
spi_BB_Write(432, 0x1072);
spi_BB_Write(433, 0x1074);
spi_BB_Write(434, 0x0071);
spi_BB_Write(435, 0x0031);
spi_BB_Write(436, 0x21BB);
spi_BB_Write(437, 0x20B1);
spi_BB_Write(438, 0x00B1);
spi_BB_Write(439, 0x10BF);
spi_BB_Write(440, 0x10B2);
spi_BB_Write(441, 0x10B4);
spi_BB_Write(442, 0x00B1);
spi_BB_Write(443, 0x0030);

spi_BB_Write(444, 0x0030);
spi_BB_Write(445, 0x217B);
spi_BB_Write(446, 0x2071);
spi_BB_Write(447, 0x0071);
spi_BB_Write(448, 0x107F);
spi_BB_Write(449, 0x1072);
spi_BB_Write(450, 0x1074);
spi_BB_Write(451, 0x0071);
spi_BB_Write(452, 0x0031);
spi_BB_Write(453, 0x21BB);
spi_BB_Write(454, 0x20B1);
spi_BB_Write(455, 0x00B1);
spi_BB_Write(456, 0x10BF);
spi_BB_Write(457, 0x10B2);
spi_BB_Write(458, 0x10B4);
spi_BB_Write(459, 0x00B1);
spi_BB_Write(460, 0x0030);

spi_BB_Write(461, 0x0030);
spi_BB_Write(462, 0x217B);
spi_BB_Write(463, 0x2071);
spi_BB_Write(464, 0x0071);
spi_BB_Write(465, 0x1071);
spi_BB_Write(466, 0x0071);
spi_BB_Write(467, 0x0031);
spi_BB_Write(468, 0x21BB);
spi_BB_Write(469, 0x20B1);
spi_BB_Write(470, 0x00B1);
spi_BB_Write(471, 0x10B3);
spi_BB_Write(472, 0x10B1);
spi_BB_Write(473, 0x00B1);
spi_BB_Write(474, 0x003F);
spi_BB_Write(475, 0x0032);
spi_BB_Write(476, 0x0030);
}

void SoftPowerUp() {

spi_BB_Write(10, 0x0000);	// Release soft reset state
#ifdef DISABLE_PLL 
	spi_BB_Write(32, 0x7007|0x0008);	// Enable analog clock
#else
	spi_BB_Write(32, 0x7007);	// Enable analog clock
#endif
spi_BB_Write(40, 0x0007);	// Enable column multiplexer // 3rd bit endables bias. This was set to 0 (0x003).
spi_BB_Write(42, 0x4113);	// spi_BB_Write(42, 0x4103); Configure image core
spi_BB_Write(48, 0x0001);	// Enable AFE
spi_BB_Write(64, 0x0001);	// Enable biasing block
spi_BB_Write(72, 0x0127);	// spi_BB_Write(72, 0x0117); Enable charge pump. 
//spi_BB_Write(112, 0x0007);	// Enable LVDS transmitters
spi_BB_Write(112, 0x0000);	// Enable LVDS transmitters
}

void NoTransfer() {
	spi_BB_Write(402, 0xF002);
}

void Transfer() {
	spi_BB_Write(402, 0xF402);
}

//////////////////////////////////////////////////////////////////////////
// function to enable E-black calibration images 
//////////////////////////////////////////////////////////////////////////
void Eblack() {			// enables electrical black image
spi_BB_Write(220, 0x3C2B);
NoTransfer();

}
//////////////////////////////////////////////////////////////////////////
// function to enable E-gray calibration images
//////////////////////////////////////////////////////////////////////////
void Egray(){				// enables electrical gray image
NoTransfer();
spi_BB_Write(220, 0x3C4D);
}


//////////////////////////////////////////////////////////////////////////
// function to (re)enable normal image mode 
//////////////////////////////////////////////////////////////////////////
void DisableE(){				// (re-)enables 'normal' image capture

Transfer();
spi_BB_Write(220, 0x3C2B);
}

void EnableSeq () {
	spi_BB_Write(192,0x0803);
}

void DisableSeq () {
	spi_BB_Write(192,0x0802);
}
#endif /* PYTHON480_H_ */