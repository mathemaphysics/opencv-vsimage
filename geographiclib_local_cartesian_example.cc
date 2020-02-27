#include <iostream>
#include <exception>
#include <cmath>
#include <GeographicLib/Geocentric.hpp>
#include <GeographicLib/LocalCartesian.hpp>

using namespace std;
using namespace GeographicLib;

int main()
{
    try
    {
        Geocentric earth(Constants::WGS84_a(), Constants::WGS84_f());
        // Alternatively: const Geocentric& earth = Geocentric::WGS84();
        const double lat0 = 48 + 50 / 60.0, lon0 = 2 + 20 / 60.0; // Paris
        cout << "Original: " << lat0 << " " << lon0 << " " << 0.0 << endl;
        LocalCartesian proj(lat0, lon0, 0, earth);
        {
            // Sample forward calculation
            double lat = 50.9, lon = 1.8, h = 0; // Calais
            double x, y, z;
            proj.Forward(lat, lon, h, x, y, z);
            cout << "Given lat, lon, h: " << lat << " " << lon << " " << h << endl;
            cout << "New delta: " << x << " " << y << " " << z << endl;
        }
        {
            // Sample reverse calculation
            double x = -38e3, y = 230e3, z = -4e3;
            double lat, lon, h;
            proj.Reverse(x, y, z, lat, lon, h);
            cout << "Given x, y, z: " << x << " " << y << " " << z << endl;
            cout << "New position: " << lat << " " << lon << " " << h << endl;
        }
    }
    catch (const exception &e)
    {
        cerr << "Caught exception: " << e.what() << "\n";
        return 1;
    }
}