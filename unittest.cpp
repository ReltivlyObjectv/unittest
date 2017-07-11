#ifdef UNIT_TEST

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <list>
#include <string>
#include "defs.h"

class unitData {
	public:
		double xin, yin, lengthout, xout, yout;
		unitData(Flt x, Flt y, Flt l, Flt x2, Flt y2)
		{
			xin = x;
			yin = y;
			lengthout = l;
			xout = x2;
			yout = y2;
		}
};

void loadUnitData();

//All data is loaded from list, so if any info is added,
//--no functionalitiy is lost or altered
std::list<unitData> testData;

int performUnitTest(double tolerance)
{
	loadUnitData();
	int errorsEncountered = 0;
	std::list<unitData>::iterator it;
	int pos = 1;
	for (it = testData.begin(); it != testData.end(); ++it) {
		Vec ki = { (*it).xin, (*it).yin };
		Vec ao = { ki[0], ki[1] };
		Flt ret = vecNormalize(ao);
		std::string error = "";
		if (fabs(ret - (*it).lengthout) > tolerance) {
			error = "<---error length";
			errorsEncountered++;
		} else if (fabs(ao[0] - (*it).xout) > tolerance) {
			error = "<---error x";
			errorsEncountered++;
		} else if (fabs(ao[1] - (*it).yout) > tolerance) {
			error = "<---error y";
			errorsEncountered++;
		}
		printf("%3i  %7.4lf  %7.4lf  %8.4lf  %7.4lf  %7.4lf%s\n",
			pos++, ki[0], ki[1], ret, ao[0], ao[1], error.c_str());
	}
	return errorsEncountered;
}

void loadUnitData()
{
	testData.push_back(*(new unitData(4.3186,6.3839,7.7074,0.5603,0.8283)));
	testData.push_back(*(new unitData(-7.3129,-6.6919,7.9126,-0.7377,-0.675)));
	testData.push_back(*(new unitData(-2.3822,-0.9827,2.5769,0.9244,-0.381)));
	testData.push_back(*(new unitData(4.2963,-7.7387,8.8513,0.4854,0.8743)));
	testData.push_back(*(new unitData(2.1622,3.2164,3.8756,0.5579,0.8299)));
	testData.push_back(*(new unitData(9.8215,-3.3814,10.3872,0.9505,-0.325)));
	testData.push_back(*(new unitData(-3.8446,-7.6765,8.5855,-0.4478,-0.889)));
	testData.push_back(*(new unitData(9.0431,-1.7387,9.2088,0.9820,-0.188)));
	testData.push_back(*(new unitData(-2.8685,9.7789,10.1910,-0.2815,0.9596)));
	testData.push_back(*(new unitData(7.0079,-3.7690,7.9572,0.8807,-0.473)));
	testData.push_back(*(new unitData(2.3359,1.5720,2.8156,0.8296,0.5583)));
	testData.push_back(*(new unitData(7.1103,-5.4922,8.9844,0.7914,-0.611)));
	testData.push_back(*(new unitData(-1.4481,7.9055,8.0370,-0.1802,0.9836)));
	testData.push_back(*(new unitData(7.1591,-2.9631,7.7481,0.9240,-0.382)));
	testData.push_back(*(new unitData(-7.0436,-8.1469,10.7696,-0.6540,-0.756)));
	testData.push_back(*(new unitData(3.2548,6.2749,7.0689,0.4604,0.8877)));
	testData.push_back(*(new unitData(7.2370,4.9419,8.7634,0.8258,0.5639)));
	testData.push_back(*(new unitData(8.5830,-5.1452,10.0071,0.8577,-0.514)));
	testData.push_back(*(new unitData(-6.0408,2.8794,6.6919,-0.9027,0.4303)));
	testData.push_back(*(new unitData(-3.8839,5.1214,6.4275,-0.6043,0.7968)));
	testData.push_back(*(new unitData(-3.9043,-4.0624,5.6344,-0.6929,-0.721)));
	testData.push_back(*(new unitData(-8.2600,1.2511,8.3542,-0.9887,0.1498)));
	testData.push_back(*(new unitData(-2.7390,9.7832,10.1594,-0.2696,0.9630)));
	testData.push_back(*(new unitData(8.5124,3.3925,9.1636,0.9289,0.3702)));
	testData.push_back(*(new unitData(9.5621,5.5204,11.0412,0.8660,0.5000)));
	testData.push_back(*(new unitData(8.6235,1.8980,8.8299,0.9766,0.2150)));
	testData.push_back(*(new unitData(-2.9077,5.7337,6.4289,-0.4523,0.8919)));
	testData.push_back(*(new unitData(5.4059,4.6443,7.1269,0.7585,0.6517)));
	testData.push_back(*(new unitData(3.6392,2.5650,4.4523,0.8174,0.5761)));
	testData.push_back(*(new unitData(-8.3189,5.5956,10.0257,-0.8298,0.5581)));
	testData.push_back(*(new unitData(3.4181,3.9360,5.2130,0.6557,0.7550)));
	testData.push_back(*(new unitData(1.8706,0.6551,1.9820,0.9438,0.3305)));
	testData.push_back(*(new unitData(-1.1221,0.4536,1.2103,-0.9271,0.3748)));
	testData.push_back(*(new unitData(4.5099,1.8371,4.8697,0.9261,0.3773)));
	testData.push_back(*(new unitData(-6.6670,9.6260,11.7093,-0.5694,0.8221)));
	testData.push_back(*(new unitData(-3.0415,-1.5713,3.4234,-0.8884,-0.459)));
	testData.push_back(*(new unitData(-4.4365,-2.3014,4.9979,-0.8877,-0.460)));
	testData.push_back(*(new unitData(8.6798,1.8245,8.8695,0.9786,0.2057)));
	testData.push_back(*(new unitData(-2.5182,7.1922,7.6204,-0.3305,0.9438)));
	testData.push_back(*(new unitData(-4.7830,-2.9561,5.6228,-0.8506,-0.525)));
	testData.push_back(*(new unitData(2.7126,-6.1595,6.7303,0.4030,-0.915)));
	testData.push_back(*(new unitData(7.9419,8.8049,11.8575,0.6698,0.7426)));
	testData.push_back(*(new unitData(8.5743,3.3478,9.2046,0.9315,0.3637)));
	testData.push_back(*(new unitData(3.4492,2.2135,4.0984,0.8416,0.5401)));
	testData.push_back(*(new unitData(-4.0872,4.1303,5.8108,-0.7034,0.7108)));
	testData.push_back(*(new unitData(-2.1909,8.3309,8.6142,-0.2543,0.9671)));
	testData.push_back(*(new unitData(-1.9337,8.6797,8.8925,-0.2175,0.9761)));
	testData.push_back(*(new unitData(-1.0140,5.9442,6.0301,-0.1682,0.9858)));
	testData.push_back(*(new unitData(-0.8667,-6.5041,6.5616,-0.1321,-0.991)));
	testData.push_back(*(new unitData(-2.2186,1.4662,2.6594,-0.8343,0.5514)));
	testData.push_back(*(new unitData(-6.8781,3.7399,7.8291,-0.8785,0.4777)));
	testData.push_back(*(new unitData(8.8949,-2.3146,9.1911,0.9678,-0.251)));
	testData.push_back(*(new unitData(-8.5615,7.5747,11.4314,-0.7490,0.6626)));
	testData.push_back(*(new unitData(8.5099,-2.0798,8.7604,0.9714,-0.237)));
	testData.push_back(*(new unitData(4.7670,-6.2730,7.8788,0.6050,-0.796)));
	testData.push_back(*(new unitData(3.9641,-2.5205,4.6975,0.8439,-0.536)));
	testData.push_back(*(new unitData(-3.4325,1.9060,3.9262,-0.8743,0.4855)));
	testData.push_back(*(new unitData(-3.7155,-4.8583,6.1162,-0.6075,-0.794)));
	testData.push_back(*(new unitData(-4.7462,8.7337,9.9400,-0.4775,0.8786)));
	testData.push_back(*(new unitData(6.3552,0.1666,6.3574,0.9997,0.0262)));
	testData.push_back(*(new unitData(2.8640,-5.8357,6.5006,0.4406,-0.897)));
	testData.push_back(*(new unitData(-1.5024,9.9304,10.0434,-0.1496,0.9887)));
	testData.push_back(*(new unitData(-7.1560,6.4836,9.6564,-0.7411,0.6714)));
	testData.push_back(*(new unitData(5.8746,0.9773,5.9553,0.9864,0.1641)));
	testData.push_back(*(new unitData(8.9795,-6.3440,10.9945,0.8167,-0.577)));
	testData.push_back(*(new unitData(-7.5565,-7.8986,10.9311,-0.6913,-0.722)));
	testData.push_back(*(new unitData(6.3959,-8.6616,10.7671,0.5940,-0.804)));
	testData.push_back(*(new unitData(-1.2132,6.8344,6.9412,-0.1748,0.9846)));
	testData.push_back(*(new unitData(7.9131,-2.7033,8.3622,0.9463,-0.323)));
	testData.push_back(*(new unitData(-5.2454,2.6801,5.8904,-0.8905,0.4550)));
	testData.push_back(*(new unitData(0.0237,7.7187,7.7187,0.0031,1.0000)));
	testData.push_back(*(new unitData(9.1596,5.5911,10.7313,0.8535,0.5210)));
	testData.push_back(*(new unitData(-0.3753,-4.5559,4.5713,-0.0821,-0.996)));
	testData.push_back(*(new unitData(9.7329,3.8785,10.4772,0.9290,0.3702)));
	testData.push_back(*(new unitData(-5.8222,6.0881,8.4239,-0.6911,0.7227)));
	testData.push_back(*(new unitData(-5.9549,6.0419,8.4832,-0.7020,0.7122)));
	testData.push_back(*(new unitData(9.2524,1.5427,9.3802,0.9864,0.1645)));
	testData.push_back(*(new unitData(5.9722,-7.9036,9.9063,0.6029,-0.797)));
	testData.push_back(*(new unitData(-1.9737,1.8468,2.7030,-0.7302,0.6833)));
	testData.push_back(*(new unitData(2.0737,-2.9942,3.6421,0.5694,-0.822)));
	testData.push_back(*(new unitData(4.5028,3.5172,5.7137,0.7881,0.6156)));
	testData.push_back(*(new unitData(-1.8928,0.8987,2.0953,-0.9033,0.4289)));
	testData.push_back(*(new unitData(3.8556,5.8940,7.0431,0.5474,0.8369)));
	testData.push_back(*(new unitData(-2.2669,1.7687,2.8753,-0.7884,0.6151)));
	testData.push_back(*(new unitData(-6.8093,1.4876,6.9699,-0.9770,0.2134)));
	testData.push_back(*(new unitData(-5.5512,2.2144,5.9765,-0.9288,0.3705)));
	testData.push_back(*(new unitData(-0.7937,-6.3915,6.4406,-0.1232,-0.992)));
	testData.push_back(*(new unitData(-2.1945,7.8310,8.1327,-0.2698,0.9629)));
	testData.push_back(*(new unitData(-1.9474,-2.4616,3.1388,-0.6204,-0.784)));
	testData.push_back(*(new unitData(1.7095,1.2305,2.1063,0.8116,0.5842)));
	testData.push_back(*(new unitData(-6.3735,4.7547,7.9516,-0.8015,0.5980)));
	testData.push_back(*(new unitData(-2.7277,-7.1211,7.6256,-0.3577,-0.933)));
	testData.push_back(*(new unitData(-3.7026,-6.7554,7.7036,-0.4806,-0.876)));
	testData.push_back(*(new unitData(-6.0247,3.3237,6.8807,-0.8756,0.4831)));
	testData.push_back(*(new unitData(4.0914,5.0490,6.4986,0.6296,0.7769)));
	testData.push_back(*(new unitData(9.3296,-1.4058,9.4349,0.9888,-0.149)));
	testData.push_back(*(new unitData(-1.4339,-2.5632,2.9370,-0.4882,-0.872)));
	testData.push_back(*(new unitData(8.4930,-7.5783,11.3825,0.7461,-0.665)));
	testData.push_back(*(new unitData(-6.6692,-3.7740,7.6629,-0.8703,-0.492)));
	testData.push_back(*(new unitData(3.1904,-4.4785,5.4987,0.5802,-0.814)));
	testData.push_back(*(new unitData(6.7137,6.6393,9.4421,0.7110,0.7032)));
	testData.push_back(*(new unitData(6.7359,-4.0800,7.8752,0.8553,-0.518)));
	testData.push_back(*(new unitData(9.2478,-5.4586,10.7386,0.8612,-0.508)));
	testData.push_back(*(new unitData(-6.2490,-2.6996,6.8072,-0.9180,-0.396)));
	testData.push_back(*(new unitData(1.0798,4.4605,4.5894,0.2353,0.9719)));
	testData.push_back(*(new unitData(7.5308,3.7063,8.3934,0.8972,0.4416)));
	testData.push_back(*(new unitData(-0.7848,-5.1968,5.2558,-0.1493,-0.988)));
	testData.push_back(*(new unitData(5.5852,4.5126,7.1804,0.7778,0.6285)));
	testData.push_back(*(new unitData(-2.9523,8.5605,9.0553,-0.3260,0.9454)));
	testData.push_back(*(new unitData(-2.1636,-8.8608,9.1212,-0.2372,-0.971)));
	testData.push_back(*(new unitData(3.6095,-2.8340,4.5891,0.7865,-0.617)));
	testData.push_back(*(new unitData(-1.2666,-7.8244,7.9263,-0.1598,-0.987)));
	testData.push_back(*(new unitData(3.6028,-2.7736,4.5468,0.7924,-0.610)));
	testData.push_back(*(new unitData(-6.4027,5.9336,8.7294,-0.7335,0.6797)));
	testData.push_back(*(new unitData(2.4524,5.7877,6.2858,0.3901,0.9208)));
	testData.push_back(*(new unitData(-8.5448,-0.8340,8.5854,-0.9953,-0.097)));
	testData.push_back(*(new unitData(2.4270,7.1911,7.5896,0.3198,0.9475)));
	testData.push_back(*(new unitData(4.0860,1.6748,4.4159,0.9253,0.3793)));
	testData.push_back(*(new unitData(-8.2676,6.8370,10.7283,-0.7706,0.6373)));
	testData.push_back(*(new unitData(7.9751,1.8122,8.1784,0.9751,0.2216)));
	testData.push_back(*(new unitData(1.2976,5.5060,5.6568,0.2294,0.9733)));
	testData.push_back(*(new unitData(-4.4815,9.5128,10.5156,-0.4262,0.9046)));
	testData.push_back(*(new unitData(9.3091,-8.8963,12.8765,0.7230,-0.690)));
	testData.push_back(*(new unitData(4.0254,-3.6432,5.4292,0.7414,-0.671)));
	testData.push_back(*(new unitData(8.6642,-8.1382,11.8869,0.7289,-0.684)));
	testData.push_back(*(new unitData(-3.5040,2.2737,4.1770,-0.8389,0.5443)));
	testData.push_back(*(new unitData(-1.9722,4.2294,4.6666,-0.4226,0.9063)));
	testData.push_back(*(new unitData(3.4492,-8.3694,9.0523,0.3810,-0.924)));
	testData.push_back(*(new unitData(-8.5443,6.0465,10.4673,-0.8163,0.5777)));
	testData.push_back(*(new unitData(6.5643,2.9081,7.1796,0.9143,0.4051)));
	testData.push_back(*(new unitData(1.8343,7.0194,7.2551,0.2528,0.9675)));
	testData.push_back(*(new unitData(-7.9259,-5.7387,9.7853,-0.8100,-0.586)));
	testData.push_back(*(new unitData(4.2105,5.1602,6.6600,0.6322,0.7748)));
	testData.push_back(*(new unitData(4.9360,4.9429,6.9855,0.7066,0.7076)));
	testData.push_back(*(new unitData(1.9972,2.9111,3.5304,0.5657,0.8246)));
	testData.push_back(*(new unitData(-3.2449,-6.7052,7.4491,-0.4356,-0.900)));
	testData.push_back(*(new unitData(-1.5829,1.2736,2.0317,-0.7791,0.6269)));
	testData.push_back(*(new unitData(-7.1925,-2.2738,7.5433,-0.9535,-0.301)));
	testData.push_back(*(new unitData(1.3773,5.8330,5.9934,0.2298,0.9732)));
	testData.push_back(*(new unitData(3.0830,0.0415,3.0833,0.9999,0.0135)));
	testData.push_back(*(new unitData(6.6948,8.5790,10.8821,0.6152,0.7884)));
	testData.push_back(*(new unitData(-7.6848,-5.2774,9.3224,-0.8243,-0.566)));
	testData.push_back(*(new unitData(2.8084,4.7644,5.5306,0.5078,0.8615)));
	testData.push_back(*(new unitData(-4.6468,3.2642,5.6787,-0.8183,0.5748)));
	testData.push_back(*(new unitData(0.8110,-8.0825,8.1231,0.0998,-0.995)));
	testData.push_back(*(new unitData(-3.8277,-7.3548,8.2912,-0.4617,-0.887)));
	testData.push_back(*(new unitData(7.9369,-2.7536,8.4010,0.9448,-0.327)));
	testData.push_back(*(new unitData(-4.0935,2.1474,4.6226,-0.8856,0.4645)));
	testData.push_back(*(new unitData(-7.5934,9.8425,12.4312,-0.6108,0.7918)));
	testData.push_back(*(new unitData(-2.9097,3.4038,4.4779,-0.6498,0.7601)));
	testData.push_back(*(new unitData(2.7536,2.8455,3.9597,0.6954,0.7186)));
	testData.push_back(*(new unitData(5.6985,-8.8293,10.5085,0.5423,-0.840)));
	testData.push_back(*(new unitData(-5.8809,7.5061,9.5355,-0.6167,0.7872)));
	testData.push_back(*(new unitData(-2.1031,4.4964,4.9639,-0.4237,0.9058)));
	testData.push_back(*(new unitData(3.3391,9.9800,10.5237,0.3173,0.9483)));
	testData.push_back(*(new unitData(-5.4621,0.0339,5.4622,-1.0000,0.0062)));
	testData.push_back(*(new unitData(8.5590,-4.1469,9.5107,0.8999,-0.436)));
	testData.push_back(*(new unitData(3.7565,1.3674,3.9976,0.9397,0.3421)));
	testData.push_back(*(new unitData(9.6175,8.1097,12.5803,0.7645,0.6446)));
	testData.push_back(*(new unitData(-5.3684,0.4285,5.3855,-0.9968,0.0796)));
	testData.push_back(*(new unitData(9.0272,-0.1961,9.0293,0.9998,-0.021)));
	testData.push_back(*(new unitData(2.0737,6.9641,7.2663,0.2854,0.9584)));
	testData.push_back(*(new unitData(6.0503,6.9802,9.2374,0.6550,0.7556)));
	testData.push_back(*(new unitData(-0.8885,7.4569,7.5097,-0.1183,0.9930)));
	testData.push_back(*(new unitData(6.8227,5.2018,8.5795,0.7952,0.6063)));
	testData.push_back(*(new unitData(0.8607,-0.4237,0.9593,0.8972,-0.441)));
	testData.push_back(*(new unitData(-1.9528,-3.4408,3.9563,-0.4936,-0.869)));
	testData.push_back(*(new unitData(-0.2529,1.1663,1.1934,-0.2119,0.9773)));
	testData.push_back(*(new unitData(-5.9347,6.6440,8.9086,-0.6662,0.7458)));
	testData.push_back(*(new unitData(-4.3373,6.4044,7.7348,-0.5607,0.8280)));
	testData.push_back(*(new unitData(6.6240,-0.7993,6.6720,0.9928,-0.119)));
	testData.push_back(*(new unitData(-3.5618,5.1830,6.2888,-0.5664,0.8242)));
	testData.push_back(*(new unitData(4.0538,9.1947,10.0487,0.4034,0.9150)));
	testData.push_back(*(new unitData(-3.4496,3.6714,5.0377,-0.6848,0.7288)));
	testData.push_back(*(new unitData(7.3044,0.1820,7.3067,0.9997,0.0249)));
	testData.push_back(*(new unitData(-5.9001,6.3316,8.6545,-0.6817,0.7316)));
	testData.push_back(*(new unitData(8.9859,5.1736,10.3689,0.8666,0.4990)));
	testData.push_back(*(new unitData(3.2956,5.0363,6.0187,0.5476,0.8368)));
	testData.push_back(*(new unitData(2.1538,-7.5929,7.8925,0.2729,-0.962)));
	testData.push_back(*(new unitData(2.4932,-1.0235,2.6951,0.9251,-0.379)));
	testData.push_back(*(new unitData(6.6089,-6.6461,9.3727,0.7051,-0.709)));
	testData.push_back(*(new unitData(7.5528,-5.3439,9.2522,0.8163,-0.577)));
	testData.push_back(*(new unitData(-1.0868,-2.7001,2.9106,-0.3734,-0.927)));
	testData.push_back(*(new unitData(4.8224,1.9785,5.2125,0.9252,0.3796)));
	testData.push_back(*(new unitData(-6.0561,9.4851,11.2536,-0.5381,0.8429)));
	testData.push_back(*(new unitData(-1.6172,9.5679,9.7036,-0.1667,0.9860)));
	testData.push_back(*(new unitData(-1.3142,3.8211,4.0407,-0.3252,0.9456)));
	testData.push_back(*(new unitData(4.7508,-7.2604,8.6766,0.5475,-0.836)));
	testData.push_back(*(new unitData(3.0158,-8.6987,9.2067,0.3276,-0.944)));
	testData.push_back(*(new unitData(5.4110,0.3201,5.4205,0.9983,0.0591)));
	testData.push_back(*(new unitData(0.4833,8.5109,8.5246,0.0567,0.9984)));
	testData.push_back(*(new unitData(-3.3483,-0.5308,3.3901,-0.9877,-0.156)));
	testData.push_back(*(new unitData(3.6845,8.9473,9.6763,0.3808,0.9247)));
	testData.push_back(*(new unitData(-5.4945,-4.1618,6.8927,-0.7971,-0.603)));
	testData.push_back(*(new unitData(-8.6456,5.9987,10.5228,-0.8216,0.5701)));
	testData.push_back(*(new unitData(3.8148,6.9633,7.9398,0.4805,0.8770)));
	testData.push_back(*(new unitData(8.3526,1.3676,8.4639,0.9869,0.1616)));
	testData.push_back(*(new unitData(-8.3806,-2.7342,8.8154,-0.9507,-0.310)));
	testData.push_back(*(new unitData(7.6675,5.4418,9.4023,0.8155,0.5788)));
	testData.push_back(*(new unitData(8.2443,-8.3886,11.7616,0.7009,-0.713)));
	testData.push_back(*(new unitData(4.9269,-3.3729,5.9708,0.8252,-0.564)));
	testData.push_back(*(new unitData(-8.8207,-6.3873,10.8905,-0.8099,-0.586)));
	testData.push_back(*(new unitData(9.4482,4.9301,10.6571,0.8866,0.4626)));
	testData.push_back(*(new unitData(-4.6476,2.4639,5.2603,-0.8835,0.4684)));
	testData.push_back(*(new unitData(5.2314,9.7634,11.0766,0.4723,0.8814)));
	testData.push_back(*(new unitData(-7.2159,-4.2853,8.3925,-0.8598,-0.510)));
	testData.push_back(*(new unitData(8.2742,-1.5642,8.4208,0.9826,-0.185)));
	testData.push_back(*(new unitData(4.1839,1.9587,4.6197,0.9057,0.4240)));
	testData.push_back(*(new unitData(-2.6169,7.6894,8.1225,-0.3222,0.9467)));
	testData.push_back(*(new unitData(6.7969,-2.2625,7.1636,0.9488,-0.315)));
	testData.push_back(*(new unitData(3.6881,0.6117,3.7385,0.9865,0.1636)));
	testData.push_back(*(new unitData(-5.2992,2.0407,5.6785,-0.9332,0.3594)));
	testData.push_back(*(new unitData(-8.0207,-4.6798,9.2861,-0.8637,-0.504)));
	testData.push_back(*(new unitData(8.3065,8.6468,11.9902,0.6928,0.7212)));
	testData.push_back(*(new unitData(9.7620,6.5508,11.7563,0.8304,0.5572)));
	testData.push_back(*(new unitData(9.2582,4.6889,10.3779,0.8921,0.4518)));
	testData.push_back(*(new unitData(-6.8221,9.4375,11.6451,-0.5858,0.8104)));
	testData.push_back(*(new unitData(7.3017,-7.3740,10.3774,0.7036,-0.710)));
	testData.push_back(*(new unitData(4.3676,-7.3460,8.5463,0.5111,-0.859)));
	testData.push_back(*(new unitData(4.0899,-0.4010,4.1095,0.9952,-0.097)));
	testData.push_back(*(new unitData(-7.5826,5.8740,9.5916,-0.7905,0.6124)));
	testData.push_back(*(new unitData(4.3137,9.6917,10.6083,0.4066,0.9136)));
	testData.push_back(*(new unitData(-5.6903,-1.5024,5.8853,-0.9669,-0.255)));
	testData.push_back(*(new unitData(1.6503,0.6928,1.7899,0.9220,0.3871)));
	testData.push_back(*(new unitData(-3.8130,-1.5527,4.1171,-0.9262,-0.377)));
	testData.push_back(*(new unitData(7.4304,8.8751,11.5749,0.6419,0.7668)));
	testData.push_back(*(new unitData(8.0590,-7.8688,11.2634,0.7155,-0.698)));
	testData.push_back(*(new unitData(0.9158,9.0383,9.0845,0.1008,0.9949)));
	testData.push_back(*(new unitData(-3.5485,-0.7776,3.6327,-0.9768,-0.214)));
	testData.push_back(*(new unitData(7.6850,-3.7865,8.5672,0.8970,-0.442)));
	testData.push_back(*(new unitData(-4.2269,6.9432,8.1286,-0.5200,0.8542)));
	testData.push_back(*(new unitData(9.9024,-2.0490,10.1122,0.9793,-0.202)));
	testData.push_back(*(new unitData(6.3807,7.2041,9.6235,0.6630,0.7486)));
	testData.push_back(*(new unitData(-0.4229,0.7483,0.8596,-0.4920,0.8706)));
	testData.push_back(*(new unitData(8.8581,-6.3330,10.8891,0.8135,-0.581)));
	testData.push_back(*(new unitData(9.3473,-8.7245,12.7863,0.7310,-0.682)));
	testData.push_back(*(new unitData(8.5410,3.6610,9.2925,0.9191,0.3940)));
	testData.push_back(*(new unitData(9.9672,-7.1493,12.2661,0.8126,-0.582)));
	testData.push_back(*(new unitData(-7.8414,1.6175,8.0065,-0.9794,0.2020)));
	testData.push_back(*(new unitData(2.5436,-2.6545,3.6764,0.6919,-0.722)));
	testData.push_back(*(new unitData(9.0648,-0.0260,9.0649,1.0000,-0.002)));
	testData.push_back(*(new unitData(-3.7794,7.1238,8.0643,-0.4687,0.8834)));
	testData.push_back(*(new unitData(1.1052,6.1364,6.2352,0.1773,0.9842)));
	testData.push_back(*(new unitData(6.1620,6.5567,8.9978,0.6848,0.7287)));
	testData.push_back(*(new unitData(-4.6412,3.8471,6.0283,-0.7699,0.6382)));
	testData.push_back(*(new unitData(-7.2299,0.1319,7.2311,-0.9998,0.0182)));
	testData.push_back(*(new unitData(0.7903,-7.3275,7.3700,0.1072,-0.994)));
	testData.push_back(*(new unitData(7.0830,-2.8290,7.6270,0.9287,-0.370)));
	testData.push_back(*(new unitData(8.8766,-3.3400,9.4842,0.9359,-0.352)));
	testData.push_back(*(new unitData(6.9194,7.7347,10.3780,0.6667,0.7453)));
	testData.push_back(*(new unitData(-0.6730,6.2667,6.3027,-0.1068,0.9943)));
	testData.push_back(*(new unitData(8.0102,-2.1320,8.2891,0.9664,-0.257)));
	testData.push_back(*(new unitData(-0.0723,7.9774,7.9778,-0.0091,1.0000)));
	testData.push_back(*(new unitData(-0.2813,1.0862,1.1220,-0.2507,0.9681)));
	testData.push_back(*(new unitData(-0.4050,-7.7377,7.7483,-0.0523,-0.998)));
	testData.push_back(*(new unitData(7.4317,-1.3402,7.5516,0.9841,-0.177)));
	testData.push_back(*(new unitData(1.2363,-6.3477,6.4669,0.1912,-0.981)));
	testData.push_back(*(new unitData(-4.2164,-7.6585,8.7425,-0.4823,-0.876)));
	testData.push_back(*(new unitData(8.7888,-8.0544,11.9212,0.7372,-0.675)));
	testData.push_back(*(new unitData(7.8981,-5.8525,9.8301,0.8035,-0.595)));
	testData.push_back(*(new unitData(4.7927,9.6683,10.7910,0.4441,0.8960)));
	testData.push_back(*(new unitData(3.2795,-4.4170,5.5013,0.5961,-0.802)));
	testData.push_back(*(new unitData(-7.6592,0.3624,7.6678,-0.9989,0.0473)));
	testData.push_back(*(new unitData(1.7541,-8.7826,8.9561,0.1959,-0.980)));
	testData.push_back(*(new unitData(6.0224,-1.3266,6.1668,0.9766,-0.215)));
	testData.push_back(*(new unitData(7.9521,-4.6506,9.2121,0.8632,-0.504)));

}

#endif
