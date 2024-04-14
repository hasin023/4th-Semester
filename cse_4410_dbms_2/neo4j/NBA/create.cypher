// Create a node
create (putin:PLAYER { name: 'Vladimir Putin', number: 37, age: 47, country: 'Russia', height: 2.07, weight: 70 })
RETURN putin

// Relationship
MATCH (putin:PLAYER { name: 'Vladimir Putin' })
CREATE (putin)-[:PLAYS_FOR { salary : 720000000 }]->(team:TEAM { name: 'LA Lakers' })
