DROP DATABASE course_db;
CREATE DATABASE course_db;
USE course_db;

CREATE TABLE  Clients (
     client_id  INT UNSIGNED NOT NULL,
     client_first_name  VARCHAR(255) NOT NULL,
     client_second_name  VARCHAR(255) NOT NULL,
     client_last_name  VARCHAR(255) NOT NULL,
     birthday  DATE NOT NULL,
     client_email  VARCHAR(255) NOT NULL,
     phone_number  INT NOT NULL
);
ALTER TABLE
     Clients  ADD PRIMARY KEY  clients_client_id_primary ( client_id );
CREATE TABLE  Points (
     point_id  INT UNSIGNED NOT NULL,
     point_address  VARCHAR(255) NOT NULL,
     point_phone  INT NOT NULL,
     time_open  TIME NOT NULL,
     time_close  TIME NOT NULL
);
ALTER TABLE
     Points  ADD PRIMARY KEY  points_point_id_primary ( point_id );
CREATE TABLE  Orders (
     order_id  INT UNSIGNED NOT NULL, 
     product  INT UNSIGNED NOT NULL,
     payment_method  TINYINT(1) NOT NULL, 
     client_num  INT UNSIGNED NOT NULL,
     status_num  TINYINT(1) NOT NULL,
     point_num  INT UNSIGNED NOT NULL,
     delivery_date  TIME NOT NULL
);
ALTER TABLE
     Orders  ADD PRIMARY KEY  orders_order_id_primary ( order_id );
CREATE TABLE  Manufacturers (
     manufacturer_id  INT UNSIGNED NOT NULL,
     manufacturer_email  VARCHAR(255) NOT NULL,
     manufacturer_name  VARCHAR(255) NOT NULL
);
ALTER TABLE
     Manufacturers  ADD PRIMARY KEY  manufacturers_manufacturer_id_primary ( manufacturer_id );
CREATE TABLE  Products (
     product_id  INT UNSIGNED NOT NULL,
     product_name  VARCHAR(255) NOT NULL,
     category  VARCHAR(255) NOT NULL,
     value_num  DOUBLE(8, 2) NOT NULL,
     count  INT NOT NULL,
     product_storage  INT UNSIGNED NOT NULL,
     size  INT NOT NULL,
     defect  TINYINT(1) NOT NULL,
     manufacturer  INT UNSIGNED NOT NULL
);
ALTER TABLE
     Products  ADD PRIMARY KEY  products_product_id_primary ( product_id );
CREATE TABLE  Robots (
     robot_id  INT UNSIGNED NOT NULL,
     order_num  INT NOT NULL,
     energy_base  INT UNSIGNED NOT NULL,
     battery  INT NOT NULL
);
ALTER TABLE
     Robots  ADD PRIMARY KEY  robots_robot_id_primary ( robot_id );
CREATE TABLE  Storages (
     storage_id  INT UNSIGNED NOT NULL,
     storage_address  VARCHAR(255) NOT NULL,
     building_owner  INT UNSIGNED NOT NULL
);
ALTER TABLE
     Storages  ADD PRIMARY KEY  storages_storage_id_primary ( storage_id );
CREATE TABLE  Owners (
     owner_id  INT UNSIGNED NOT NULL,
     owner_first_name  VARCHAR(255) NOT NULL,
     owner_second_name  VARCHAR(255) NOT NULL,
     owner_last_name  VARCHAR(255) NOT NULL,
     phone_number  INT NOT NULL,
     owner_email  VARCHAR(255) NOT NULL
);
ALTER TABLE
     Owners  ADD PRIMARY KEY  owners_owner_id_primary ( owner_id );
CREATE TABLE  Bases (
     base_id  INT UNSIGNED NOT NULL,
     base_name  VARCHAR(255) NOT NULL,
     base_storage  INT UNSIGNED NOT NULL
);
ALTER TABLE
     Bases  ADD PRIMARY KEY  bases_base_id_primary ( base_id );
ALTER TABLE
     Orders  ADD CONSTRAINT  orders_client_num_foreign  FOREIGN KEY( client_num ) REFERENCES  Clients ( client_id );
ALTER TABLE
     Orders  ADD CONSTRAINT  orders_point_num_foreign  FOREIGN KEY( point_num ) REFERENCES  Points ( point_id );
ALTER TABLE
     Orders  ADD CONSTRAINT  orders_product_foreign  FOREIGN KEY( product ) REFERENCES  Products ( product_id );
ALTER TABLE
     Products  ADD CONSTRAINT  products_manufacturer_foreign  FOREIGN KEY( manufacturer ) REFERENCES  Manufacturers ( manufacturer_id );
ALTER TABLE
     Products  ADD CONSTRAINT  products_product_storage_foreign  FOREIGN KEY( product_storage ) REFERENCES  Storages ( storage_id );
ALTER TABLE
     Storages  ADD CONSTRAINT  storages_building_owner_foreign  FOREIGN KEY( building_owner ) REFERENCES  Owners ( owner_id );
ALTER TABLE
     Robots  ADD CONSTRAINT  robots_energy_base_foreign  FOREIGN KEY( energy_base ) REFERENCES  Bases ( base_id );
ALTER TABLE
     Bases  ADD CONSTRAINT  bases_base_storage_foreign  FOREIGN KEY( base_storage ) REFERENCES  Storages ( storage_id );