#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
#include "hittable.h"

#include <memory>
#include <vector> 



using std::vector;
using std::make_shared;



class object_container: public hittable_object {
	public:
		std::vector<std::shared_ptr<hittable_object>> objects;
		object_container() {};
		object_container(std::shared_ptr<hittable_object> object) { add(object);}

		void add(std::shared_ptr<hittable_object> object){
			objects.push_back(object);
		}

		bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override {
			hit_record temp_rec;
			bool hit_obj;

			auto closest_to_hit = t_max;
			for (const auto& object:objects)
			{
				// Check ray intersects with object
				if(object->hit(r,t_min,closest_to_hit,temp_rec))
				{
					hit_obj = true;
					closest_to_hit = temp_rec.t;
					rec = temp_rec;
				}
			}

			return hit_obj;
		}




};





#endif // !HITTABLE_LIST_H
