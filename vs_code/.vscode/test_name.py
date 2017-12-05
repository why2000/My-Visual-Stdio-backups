import unittest
from pylearning import get_formatted_name
class nametestcase(unittest.TestCase):
    def test_first_last_name(self):
        formatted_name = get_formatted_name('Wu',"tree")
        self.assertEqual(formatted_name,"Wu Tree")
        self.assertEqual(formatted_name,"Wu Tree")
unittest.main()
