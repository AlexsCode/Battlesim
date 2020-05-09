SELECT ShipName,Ammo,Damage
FROM ammos 
JOIN ships 
ON ammos.WeaponSystem = ships.WeaponSystem
