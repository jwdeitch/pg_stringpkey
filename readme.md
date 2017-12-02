This project seeks to add functionality to postgres to add a unique string key type. Instead of a more typical `bigserial` or `int` primary key; (which can possibly introduce data leakage and data enumeration), a random string is produce instead per the following signature:

`create_random_key(size_t length, int collision_sensitivity)`

where the length is the desired minimum length of the key to produce, and the collision_sensitivity will control at which point the length should increment. If the sensitivity is low, performance will be worse, but key size will grow slower.

The collision_sensitivity will default to 5, indicating that the length of the column will grow if there is a 1 in 5 chance of a collision with an existing value.


Credit:
Cmake files are copied & modified from TimescaleDB source: http://www.timescale.com/
Licensed under the Apache 2 license, a copy is supplied in this repository.

