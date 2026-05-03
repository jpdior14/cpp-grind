#include <iostream>
#include <string>

template <typename T>
class JD_DeliveryBox {
private:
	T warehouse_item;

public:
	JD_DeliveryBox(T inbound_payload) {
		warehouse_item = inbound_payload;
	}

	void scan_robot_payload() {
		std::cout << "[JD Logistics Bot 004]: Scanned Payload Info -> " << warehouse_item << '\n';
	}
};

int main() {
	std::cout << "=== JD.COM SMART WAREHOUSE DEPLOYMENT ===\n\n";

	std::cout << "-- Conveyor Belt 1 (Tech Weights in Kg) --\n";
	JD_DeliveryBox<int> heavy_tech_box {45};
	heavy_tech_box.scan_robot_payload();

	std::cout << "\n-- Conveyor Belt 2 (Exact Finances) --\n";
	JD_DeliveryBox<double> billing_box {399.99};
	billing_box.scan_robot_payload();

	std::cout << "\n-- Conveyor Belt 3 (Hardware Destination) --\n";
	JD_DeliveryBox<std::string> shipping_label {"To Yaounde: Core Router v2"};
	shipping_label.scan_robot_payload();

	std::cout << "\nStatus: ZERO REDUNDANT CLASSES CREATED. TEMPLATE OVERRIDE MAXIMUM EFFICIENCY!\n";

	return 0;
}
